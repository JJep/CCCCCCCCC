//
//  main.c
//  SerialPorts
//
//  Created by Jep Xia on 2017/11/19.
//  Copyright © 2017年 Jep Xia. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <fcntl.h>

int open_port();
int set_opt(int fd, int nSpeed, int nBits, char nEvent, int nStop);

struct termio
{
    unsigned short c_iflag;
    unsigned short c_oflag;
    unsigned short c_cflag;
    unsigned short c_lfalg;
    unsigned short c_line;
    unsigned short c_cc[NCCS];
};

int main(void)
{
    int fd;
    int readByte, i;
    char buff[1024];
    printf("Start...\n");
    fd = open_port(); //打开串口
    
    set_opt(fd, 115200, 8, 'N', '1');
    printf("Reading...\n");
    while(readByte <= 0)
        readByte = read(fd, buff, 500);
    printf("readByte = %d\n", readByte);
    printf("%s\n", buff);
    close(fd);
    return 0;
}

int open_port()
{
    int fd;
    fd = open("dev/ttyS0", O_RDWR, O_NOCTTY, O_NDELAY);
    printf("fcntl = %d\n", fcntl(fd, F_SETFL, 0));
    printf("isatty succes\n");
    return fd;
}

int set_opt(int fd, int nSpeed, int nBits, char nEvent, int nStop)
{
    struct termios newtio,oldtio;
    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag |= CLOCAL | CREAD;
    newtio.c_cflag &= ~CSIZE;
    newtio.c_cflag |= CS8;
    newtio.c_cflag &= ~PARENB;
    cfsetispeed(&newtio, B115200);
    cfsetospeed(&newtio, B115200);
    newtio.c_cflag &= ~CSTOPB;
    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN] = 0;
    tcflush(fd, TCIFLUSH);
    printf("set done\n");
    return 0 ;
}
