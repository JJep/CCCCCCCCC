//
//  server.c
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

main()
{
    int sockfd, new_fd, numbytes;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    int sin_size;
    char buff[100];
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0 )) == -1)
    {
        perror("socket");
        exit(1);
    }
    printf("Socket success!, sockfd = %d \n",sockfd);
    
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(4321);
    
    my_addr.sin_addr.s_addr = INADDR_ANY;
    
    bzero(&(my_addr.sin_zero), 8);
    
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))) {
        perror("bind");
        exit(1);
    }
    printf("bind Success/n");
    
    if (listen(sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }
    printf("listening../n");
    
    while (1) {
        sin_size = sizeof(struct sockaddr_in);
        if ((new_fd = accept(sockfd, (struct sockaddr * )&their_addr, &sin_size)) == -1 ){
            perror("accept");
            exit(1);
        }
        
        if (!(fork())) {
            if ((numbytes = recv(new_fd, buff, strlen(buff), 0)) == -1) {
                perror("recv");
                exit(1);
            }
            printf("%s \n",buff);
            
            if (send(new_fd, "Welcome, This is Server.", strlen(buff), 0) == -1)
                perror("send");
            
            close(new_fd);
            exit(0);
        }
        
    }
    close(sockfd);
}
