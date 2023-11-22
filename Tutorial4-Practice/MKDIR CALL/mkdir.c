#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(void){
    int ret = mkdir("tmp", 0777);

    if (ret == -1){
        printf("ERROR");
        return 1;
    }

    printf("CREATED NEW DIRECTORY");
}