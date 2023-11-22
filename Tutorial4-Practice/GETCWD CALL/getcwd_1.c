//USE PATHCONF TO GET MAXIMUM PATH LENGTH
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void){
    //GET MAXIMUM PATH LENGTH
    int maxpath = pathconf("/", _PC_PATH_MAX);

    //DECLARE BUFFER
    char buffer[maxpath];

    if (getcwd(buffer, maxpath) == NULL){
        printf("COULD NOT GET CWD");
        exit(1);
    }
    else{
        printf("CWD: %s\n", buffer);
        exit(0);
    }
}