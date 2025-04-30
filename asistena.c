#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main(){
    int id = shmget(1234, 512, 0666 | IPC_CREAT);
    char *ptr = (char*)shmat(id, NULL, 0);

    while (ptr[0] == 0) usleep(100000);
    printf("asisten: %s\n", ptr);

    strcpy(ptr + 256, "Boleh, nanti malam ya");

    shmdt(ptr);
    shmctl(id, IPC_RMID, 0);
    return 0;
}
