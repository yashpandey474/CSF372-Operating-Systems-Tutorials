#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
    int pid;
    int status;
    printf("BEFORE FORKING\n");

    pid = fork();

    if (pid == -1){
        printf("FORK FAILED\n");
        exit(1);
    }
    if (pid == 0){
        printf("CHILD PROCESS\n");
    }
    else {
        printf("PARENT PROCESS GOING TO WAIT\n");
        wait(&status);
        printf("PARENT PROCESS IS BACK\n");
    }
    printf("PROCESS EXITING: %d\n", getpid());
}