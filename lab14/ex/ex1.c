#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define FILE_LENGTH 0x01

int main(int argc, char *argv[]){
    int fd, count;  
    char ch;
    void *fiile_memory;

    fd = open(argv[1], O_RDWR, S_IRUSR |  S_IWUSR);

    lseek(fd, 1, SEEK_SET);
    write(fd, "", 1);

    fiile_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);

    close(fd);

    printf("enter any character:\n");
    scanf("%c", &ch);

    getchar();
    sprintf((char*) fiile_memory, "%c", ch);
    printf("You can open another terminal use 'more' to check file..\n");

    getchar();

    munmap((char*) fiile_memory, FILE_LENGTH);
    return 0;
}