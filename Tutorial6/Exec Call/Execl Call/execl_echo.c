#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){

    execl("/bin/echo", "echo", "Print", "from", "execl", NULL);
    //DOESNT RETURN BACK FROM EXEC!
    printf("HELLO WORLD!\n");
}