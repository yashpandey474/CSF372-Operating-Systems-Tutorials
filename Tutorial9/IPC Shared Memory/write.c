//WRITING TO SHARED MEMORY
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    //GENERATE AN UNIQUE KEY
    key_t key = ftok("systemcalls.txt", 65);

    if (key == -1){
        printf("COULD NOT GENERATE KEY\n");
        exit(1);
    }

    //GENERATE A SHMID USING SHMGET
    int shmid = shmget(
        key, //UNIQUE KEY
        1024, //SIZE OF SHARED MEMORY
        0666 | IPC_CREAT //MODE TO CREATE
        );

    //GET THE ATTACHED MEMORY POINTER USING SHMAT
    char* str = shmat(
        shmid, //PASS THE SHARED MEMORY ID
        (void*) 0, //NOTHING HERE
        0 //NOTHING HERE FOR FLAG
        );

    //WRITE INTO SHARED MEMORY

    //GET INPUT INTO STR
    gets(str);

    //AUTOMATICALLY WRITTEN
    printf("DATA WRITTEN INTO MEMORY: %s\n", str);

    //DETACH MEMORY USING POINTER STR
    shmdt(str);

    exit(0);
}