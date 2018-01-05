#include <stdio.h>
#include <fcntl.h> // for open(), close(), read()
#include <string.h> // for memset()
#include <sys/select.h> // for FD_*, select()
#include <limits.h> // for PIPE_BUF

int main(int argc, char const *argv[])
{
    char buffer[PIPE_BUF];
    fd_set fdset;
    struct timeval tv;
    int maxfd, ready;
    int fd1 = open("fifo1", O_RDWR);
    int fd2 = open("fifo2", O_RDWR);
    
    if (fd1 > fd2){
        maxfd = fd1;
    }else {
        maxfd = fd2;
    }

    while(1){
        FD_ZERO(&fdset);
        FD_SET(fd1, &fdset);
        FD_SET(fd2, &fdset);
        tv.tv_sec = 2;

        memset(&buffer, 0, PIPE_BUF);
        if((ready = select(maxfd+1, &fdset, NULL, NULL, &tv)) < 0)
        {
            printf("fuck\n");
        }
        else if(ready == 0)
        {
            printf("Timeout.  Try another select().\n");
        }
        else
        {
            if(FD_ISSET(fd1, &fdset))
            {
                printf("DEVICE 1 can read.\n");
                read(fd1, &buffer, PIPE_BUF);
                printf("%s\n", buffer);
            }
            if(FD_ISSET(fd2, &fdset))
            {                                                                                       
                printf("DEVICE 2 can read.\n");
                read(fd2, &buffer, PIPE_BUF);
                printf("%s\n", buffer);
            }
        }
    }   

    return 0;
}