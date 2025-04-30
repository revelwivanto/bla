#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main(){
    int id = shmget(1234, 512, 0666 | IPC_CREAT);
    char *ptr = (char*)shmat(id, NULL, 0);

    memset(ptr, 0, 512);
    strcpy(ptr, "Halo mas, bisa demo kapan?");
    printf("praktikan: %s\n", ptr);

    while (ptr[256] == 0) usleep(100000);
    printf("praktikan: %s\n", ptr + 256);

    shmdt(ptr);
    return 0;
}
