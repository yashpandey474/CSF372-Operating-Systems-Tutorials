#include <unistd.h>

int main(void){
    char* binaryPath = "/bin/bash";
    char* args[] = {binaryPath, "-c", NULL};
    char* const env[] = {NULL};
    execve(binaryPath, args, env);
}