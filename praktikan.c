#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main(){
    key_t key=1234;
    int id=shmget(key,256,0666|IPC_CREAT);
    char* ptr=(char*)shmat(id,NULL,0);
    memset(ptr,0,256);
    strcpy(ptr,"Halo mas, bisa demo kapan?");
    shmdt(ptr);
    return 0;
}
