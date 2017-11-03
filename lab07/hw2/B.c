// gcc B.c -lrt -o b.out
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    // the size (int byte) of shared memory object
    const int SIZE = 4096;
    // name of shared memory object
    const char *name = "OS";
    // shared memory file descriptor
    int shm_fd;
    // pointer to shared object
    void *ptr;


    // open the shared memory object
    shm_fd = shm_open(name, O_RDONLY, 0666);

    // memory map the shared memory object
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    // read from the shared memory object
    printf("%s", (char *)ptr);
    printf("\n");

    //remove the shared memory object
    shm_unlink(name); 
    
    return 0;
}
