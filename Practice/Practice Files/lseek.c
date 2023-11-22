#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i = 0;
    if (fork() && fork()){
        if (fork() || fork()){
            fork();
        }
    }
    printf("F\n");
}