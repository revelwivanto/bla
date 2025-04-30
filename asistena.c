#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main(){
    int id=shmget(1234,512,0666);
    char*ptr=(char*)shmat(id,0,0);
    while(ptr[0]==0)usleep(100000);
    printf("Praktikan: %s\n",ptr);
    strcpy(ptr+256,"Boleh, nanti malam ya");
    shmdt(ptr);
    return 0;
}
