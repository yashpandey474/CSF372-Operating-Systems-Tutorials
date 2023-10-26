#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>


int main(){

    //OPENING DIRECTORY
    DIR* ds;
    int cld;

    //READING DIRECTORY
    struct dirent *dir;

    //OPENING DIRECTORY
    char* buf;
    long max;

    max = pathconf("/", _PC_PATH_MAX);
    buf = (char*)malloc(max);

    //GET CWD
    if (getcwd(buf, max) == NULL){
        printf("ERROR: COULD NOT OPEN CWD");
        return 0;
    }
    
    //PRINT CWD
    printf("PATH: CWD IS %s\n", buf);

    //OPEN CWD
    ds = opendir(buf);

    if (ds == NULL){
        printf("ERROR: COULD NOT OPEN CWD\n");
        return 0;
    }

    printf("LIST OF FILES AND DIRECTORIES IN CWD\n");

    while ((dir = readdir(ds)) != NULL){
        printf("%s\n", dir->d_name);
    }

    if ((cld = closedir(ds)) != 0){
        printf("ERROR: COULD NOT CLOSE CWD");
        return 0;
    }

    printf("SUCCESSFULLY CLOSED CWD\n");
    return 0;

}