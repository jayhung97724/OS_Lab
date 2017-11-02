// gcc A.c -lrt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    // the size (int byte) of shared memory object
    const int SIZE = 4096;
    // name of shared memory object
    const char *name = "OS";
    //strings written to shared memory
    const char *message_0 = "Hello";
    const char *message_1 = "World!";
    // shared memory file descriptor
    int shm_fd;
    // pointer to shared object
    void *ptr;

    char buf[256];


    // create the shared memory object
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    // configure the size of the shared memory object
    ftruncate(shm_fd, SIZE);

    // memory map the shared memory object
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // write to the shared memory object
    printf("Enter some text: ");
    fgets(buf, sizeof(buf), stdin);
    sprintf(ptr, "%s", buf);
    ptr += strlen(buf);

    return 0;
}
