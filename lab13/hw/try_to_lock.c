#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

struct flock* file_lock(short type, short whence)
{
        static struct flock ret;
        ret.l_type = type;
        ret.l_start = 0;
        ret.l_whence = whence;
        ret.l_len = 0;
        return &ret;
}

int main()
{
        int input,  flag,  unlock;
        char ca[100];
        int fd = open("lock.txt",  O_RDWR|O_APPEND);
        printf("Choosing lock:\n");
        printf("1. exclusive lock(write lock). 2. share lock(read lock). 3. Not use lock.\n");
        scanf("%d", &input);
        if(input == 1) {
                flag = fcntl(fd, F_SETLK, file_lock(F_WRLCK, SEEK_SET));
                if(flag == -1)  printf("Locking file with 'WRLCk' failed,  another process has locked it.\n");
                else {
                        fcntl(fd, F_SETLK, file_lock(F_WRLCK, SEEK_SET));
                        printf("Locking file with 'WRLCk' succeeded,  enter any integer to unlock.\n");
                }
        }
        else if(input == 2) {
                flag = fcntl(fd, F_SETLK, file_lock(F_RDLCK, SEEK_SET));
                if(flag == -1)  printf("Locking file with 'RDLCk' failed,  another process has locked it.\n");
                else{   
                        fcntl(fd, F_SETLK, file_lock(F_RDLCK, SEEK_SET));
                        printf("Locking file with 'RDLCk' succeeded, reading file...\n");
                        read(fd, ca, 100);
                        puts(ca);
                }       
        }else if(input == 3) {
                printf("Reading.........\n");
                read(fd, ca, 100);
                puts(ca);
        }

        return 0;
}
