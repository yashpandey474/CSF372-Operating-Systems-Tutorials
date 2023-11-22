#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void){
    int cnt = 0;
    int pid;
    for (cnt  = 0; cnt < 3; cnt ++){
        pid = fork();
        if (pid == 0){
            continue;
        }
        else{
            break;
        }
    }

    printf("PROCESS: %d\n", getpid());
    printf("PARENT PROCESS: %d\n", getppiid());
    return 0;
}