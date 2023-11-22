#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int main(){
    int md, rd;

    md = mkdir("new_directory", 0777);

    if (md == 0){
        printf("DIRECTORY SUCCESSFULLY CREATED\n");
    }
    else{
        printf("ERROR: COULD NOT CREATE NEW DIRECTORY\n");
        return 1;
    }

    rd = rmdir("new_directory");

    if (rd == 0){
        printf("DIRECTORY REMOVED\n");
    }
    else{
        printf("ERROR: COULD NOT REMOVE NNEW DIRECTORY\n");
    }

    return 0;
}