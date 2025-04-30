#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int id = shmget(1234, 512, 0666 | IPC_CREAT);
    char* ptr = (char*) shmat(id, 0, 0);
    memset(ptr, 0, 512);
    if (argc > 1) strcpy(ptr, argv[1]);
    printf("praktikan: %s\n", ptr);
    while (ptr[256] == 0) usleep(100000); 
    printf("praktikan: %s\n", ptr + 256);
    shmdt(ptr);
    shmctl(id, IPC_RMID, 0); 
    return 0;
}
