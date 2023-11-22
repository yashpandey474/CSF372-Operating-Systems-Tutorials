//DISPLAY THE FILES IN CURRENT WORKING DIRECTORY
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
// #include <fcntl.h>
//REQUIRED BY OPENDIR, CLOSEDIR, READDIR
#include <dirent.h>

int main(void){
    //GET THE PATH OF CWD
    int pathMax = pathconf("/", _PC_PATH_MAX);
    char path[pathMax];
    int ret;

    if (getcwd(path, pathMax) == NULL){
        printf("COULD NOT GET PATH OF CWD\n");
        exit(1);
    }

    //OPEN DIRECTORY STREAM
    DIR* dir = opendir(path);

    //GET ENTRIES FROM DIRECTORY STREAM
    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL){
        //SKIP OVER CURRENT DIRECTORY & PARENT DIRECTORY ENTRIES
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
            continue;
        }

        printf("%s\n", entry->d_name);
    }

    //CLOSE THE DIRECTORY
    ret = closedir(dir);
    if (ret == -1){
        printf("COULD NOT CLOSE CWD\n");
        exit(1);
    }
    printf("SUCCESSFUL!\n");
    return 0;
}