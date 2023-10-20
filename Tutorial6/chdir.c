#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char cwd[256];

    //INT CHDIR(CHAR* PATHNAME);
    if (chdir("/tmp") != 0){
        printf("ERROR: COULD NOT CHANGE CWD");
    }
    else{
        //GET CWD
        if (getcwd(cwd, 256) == NULL){
            printf("ERROR: COULD NOT GET CWD");
        }
        else{
            printf("PATH: CWD IS %s\n", cwd);
        }
    }
    return 0;
}