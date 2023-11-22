#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>


int main(void){

    long max;

    char* buf;

    max = pathconf("/", _PC_PATH_MAX);

    buf = (char*)malloc(max);

    if (getcwd(buf, max) == NULL){
        printf("ERROR: COULD NOT OBTAIN WORKING DIRECTORY\n");
    }
    else{
        printf("PATH: CURRENT WORKING DIRECTORY IS: %s\n", buf);
    }

    return 0;
}
