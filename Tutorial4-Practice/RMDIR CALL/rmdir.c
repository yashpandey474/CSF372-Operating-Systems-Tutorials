#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>


int main(void){
    //MAKE A DIRECTORY
    int ret = mkdir("tmp", 0777);

    if(ret == -1){
        printf("COULD NOT MAKE DIRECTORY\n");
        return 1;
    }

    //REMOVE THE DIRECTORY
    ret = rmdir("tmp");

    if (ret == -1){
        printf("COULD NOT REMOVE DIRECTORY\n");
        return 1;
    }

    printf("SUCCESSFUL!\n");
}