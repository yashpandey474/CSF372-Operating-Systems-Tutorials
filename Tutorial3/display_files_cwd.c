#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(void){
    struct dirent *de; //POINTER FOR DIRECTORY ENTRY

    DIR *dr = opendir(".");

    if (dr == NULL){
        printf("COULD NOT OPEN CURRENT DIRECTORY");
        return 0;
    }

    while ((de = readdir(dr)) != NULL){
        //SKIP CURRENT DIRECTORY & PARENT DIRECTORY ENTRIES
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0){
            continue;
        }
        printf("%s\n", de->d_name);
    }

    closedir(dr);
    return 0;
}