#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#ifndef PATH_MAX
#define PATH_MAX 255
#endif


int main(void){
    char dirname[PATH_MAX + 1];

    if (getcwd(dirname, PATH_MAX) == NULL){
        printf("ERROR: COULD NOT OBTAIN CURRENT WORKING DIRECTORY\n");
    }
    else{
        printf("PATH: CURRENT WORKING DIRECTORY IS %s\n", dirname);   
    }

    return 0;
}
