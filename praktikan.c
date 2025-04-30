#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main(int argc,char*argv[]){
    key_t key=1234;
    int id=shmget(key,256,0666|IPC_CREAT);
    char*ptr=(char*)shmat(id,NULL,0);
    if(argc>1)strcpy(ptr,argv[1]);
    printf("praktikan: %s\n",ptr);
    shmdt(ptr);
    return 0;
}
