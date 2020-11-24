#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>
#define SHM_SEGMENT "/shm_segment"
#define MODES 0666
typedef struct
{
    int client_wrote;
    char text[BUFSIZ];
} shared_struct;
int main()
{
    int shmd;
    // shared_struct *segment;

    shmd = shm_open(SHM_SEGMENT, O_RDWR, MODES);
    ftruncate(shmd, 1000);
    void * segment =
        mmap(NULL, 1000, PROT_WRITE,
             MAP_SHARED, shmd, 0);
    sprintf(segment, "Hello, world.");

    munmap((char *)segment, 1000);
    return 0;
}