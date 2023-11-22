#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>


#ifndef PATH_MAX
#define PATH_MAX 255
#endif


int main(void){
    char dirname[PATH_MAX + 1];

    if (getcwd(dirname, PATH_MAX) == NULL){
        printf("ERROR");
        exit(1);
    }
    else{
        printf("CWD: %s\n", dirname);
        exit(0);
    }
}