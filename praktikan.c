#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main(){
    key_t key = 1234;
    int id = shmget(key, 256, 0666);
    char* ptr = (char*) shmat(id, NULL, 0);

    char last[256] = {0}; 

    while(1){
        if(ptr[0] != '\0' && strcmp(ptr, last) != 0){
            printf("Asisten: %s\n", ptr);
            strcpy(last, ptr); 
        }
        usleep(100000); 
    }

    shmdt(ptr);
    shmctl(id, IPC_RMID, NULL);
    return 0;
}
