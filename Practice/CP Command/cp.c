
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    int srcFD, destFD;

    //PATHNAME, SOURCE FILE, DESTFILE
    if (argc != 3){
        printf("NOT ENOUGH ARGUMENTS\n");
        exit(1);
    }

    //GET THE SOURCE FILE OPEN [2ND ARGUMENT]
    srcFD = open(argv[1], O_RDONLY);
    if (srcFD == -1){
        printf("COULDN'T OPEN SOURCE\n");
        exit(1);
    }

    //GET DEST FILE OPENED
    destFD = open(argv[2], O_WRONLY);
    if (destFD == -1){
        printf("COULDN'T OPEN DEST\n");
        exit(1);
    }

    //READ FROM SOURCE
    char buff[256];
    while(read(srcFD, buff, sizeof(buff)) > 0){
        if (write(destFD, buff, sizeof(buff)) == -1){
            printf("COULD NOT WRITE\n");
        }
    }

    close(srcFD);
    close(destFD);
}
