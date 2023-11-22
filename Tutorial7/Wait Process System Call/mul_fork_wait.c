#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
    pid_t whichone, first, second;
    int howmany, status;

    if ((first = fork()) == 0){
        printf("IN CHILD PROCESS: %d\n", getpid());
        exit(0);
    }
    if ((second = fork()) == 0){
        printf("IN CHILD PROCESS: %d\n", getpid());
        exit(0);
    }

    printf("IN PARENT PROCESS: %d\n", getpid());
    
    howmany = 0;
    while (howmany < 2){
        whichone = wait(&status);
        howmany += 1;

        if (whichone == first){
            printf("FIRST CHILD EXITED\n");
        }
        else {
            printf("SECOND CHILD EXITED\n");
        }
    }


}