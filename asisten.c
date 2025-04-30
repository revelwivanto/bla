#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main(){
    key_t key=1234;
    int id=shmget(key,256,0666);
    char*ptr=(char*)shmat(id,NULL,0);
    while(ptr[0]=='\0')usleep(100000);
    printf("Asisten: %s\n",ptr);
    shmdt(ptr);
    shmctl(id,IPC_RMID,NULL);
    return 0;
}
