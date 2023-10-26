#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int pid;
    printf("BEFORE FORK\n");

    system("ps");

    pid = fork();

    if (pid == 0){
        printf("AFTER FORK\n");
        printf("CHILD PID: %d\n", getpid());
        execlp("echo", "echo", "hello", "world", (char*)NULL);
    }
    else{
        printf("PARENT PID: %d\n", getpid());
        printf("CHILD PID = %d\n", pid);
    }
}