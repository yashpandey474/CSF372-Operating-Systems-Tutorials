#include <unistd.h>

int main(void){
    //NO P => PATHNAME AS FIRST ARGUMENT
    char* binaryPath = "/bin/ls";
    //PATHNAME IS FIRST ARGUMENT IN VECTOR TOO
    char* args[] = {binaryPath, "-lh", "/home", NULL};
    execv(binaryPath, args);
}