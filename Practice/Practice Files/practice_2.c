#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char* args[] = {"hello", 0, 0, NULL};

    pid_t pid = vfork();

    if (pid == 0){
        printf("C");
    }
    else{
        printf("P");
        execv("./hello", args);
        printf("R");
    }
    printf("F");
    return 0;
}