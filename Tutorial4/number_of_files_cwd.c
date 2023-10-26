#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main(){
    //GET NAME OF CWD
    long max;
    char* buf;

    max = pathconf("/", _PC_PATH_MAX);
    buf = (char*)malloc(max);

    //GET CWD
    if (getcwd(buf, max) == NULL){
        printf("ERROR: COULD NOT GET CWD\n");
        return 0;
    }

    //OPEN CWD
    DIR* ds;
    int cld;
    struct dirent* dir;

    ds = opendir(buf);

    //IF DIR* IS NULL: ERROR
    if (ds == NULL){
        printf("ERROR: COULD NOT OPEN CWD");
        return 0;
    }

    //READ FROM DS
    int count_files = 0;
    while ((dir = readdir(ds)) != NULL){
        //IF A REGULAR FILE
        if (dir -> d_type == DT_REG){
            count_files += 1;
        }
    }

    //CLOSE DS
    if ((cld = closedir(ds)) != 0){
        printf("ERROR: COULD NOT CLOSE DIRECTORY");
    }
    printf("TOTAL NUMBER OF FILES IN CWD: %d\n", count_files);
    printf("SUCCESSFULLY CLOSED CWD");
    return 0;
}