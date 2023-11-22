//READ FROM SHARED MEMORY
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main (void){
    //GET THE GENERATED KEY
    key_t key = ftok("systemcalls.txt", 65);

    //GET THE SHARED MEMORY ID
    int shmid = shmget(
        key,
        1024,
        0666 | IPC_CREAT //NOTE: IPC_CREAT PASSED FOR READER TOO!
    );

    //READ FROM THE MEMORY
    char* str = (char*) shmat(
        shmid,
        (void*) 0,
        0
    );

    //PRINT THE OUTPUT
    printf("DATA READ FROM MEMORY: %s\n", str);

    //DETACH FROM MEMORY
    shmdt(str);

    exit(EXIT_SUCCESS);
}   