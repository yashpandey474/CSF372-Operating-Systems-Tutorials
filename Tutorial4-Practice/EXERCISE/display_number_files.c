//DISPLAY NUMBER OF FILES IN CWD
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void){
    //GET THE PATH OF CWD
    int pathMax = pathconf("/", _PC_PATH_MAX);
    char buff[pathMax];

    if (getcwd(buff, pathMax) == NULL){
        printf("COULD NOT GET CWD\n");
        exit(1);
    }

    //OPEN THE CWD TO READ
    DIR* dirStream = opendir(buff);

    //READ FROM CWD
    struct dirent* entry;
    int count;
    while ((entry = readdir(dirStream)) != NULL){
        if (entry->d_type == DT_REG){
            printf("%s\n", entry->d_name);
            count += 1;
        }
        
    }
    printf("COUNT OF FILES IN CWD: %d\n", count);
    closedir(dirStream);
}