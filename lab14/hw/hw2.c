#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define FILE_LENGTH 0x50

int main (int argc, char *argv[]) {
    int fd, count, start, end;
    char str[80] = {0};
    void *file_memory;
    
    fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);
    start = atoi(argv[2]);
    end = atoi(argv[3]);
    file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);

    close(fd);

    printf("Substring from %d to %d is:\n", start, end);
    sscanf((char*) file_memory,"%s",str);
    int i = 0;
    for (i = start; i <= end; i++){
        printf("%c", str[i]);
    }
    printf("\n");
    munmap((char*)file_memory, FILE_LENGTH);
    return 0;
}