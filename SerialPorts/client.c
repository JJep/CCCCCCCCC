//
//  clien.c
//  SerialPorts
//
//  Created by Jep Xia on 2017/11/20.
//  Copyright © 2017年 Jep Xia. All rights reserved.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

int main (int argc, char * argv[]) {
    int sockfd, numbytes;
    char buf[100];
    struct hostent * he;
    struct sockaddr_in their_addr;
    int i = 0;
    he = gethostbyname(argv[1]);
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(4321);
    their_addr.sin_addr = * ((struct in_addr *)he -> h_addr);
    bzero(&(their_addr.sin_zero), 8);
    
    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }
    
    if (send(sockfd, "Hello! I am Jep!", 6, 0) == -1) {
        perror("send");
        exit(1);
    }
    
    if ((numbytes = recv(sockfd, buf, 100, 0)) == -1) {
        perror("recv");
        exit(1);
    }
    
    printf("result : %s \n",buf);
    close(sockfd);
    return 0;
}

