#define BUFF_SIZE 256
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    int srcFD, destFD, nbread, nbwrite;
    char *buff[BUFF_SIZE];

    if (argc != 3){
        printf("\nPLEASE ENTER THE FILE NAMES");
        exit(1);
    }
    srcFD = open(argv[1], O_RDONLY);
    if (srcFD == -1){
        printf("\nERROR IN OPENING FILE");
        return 1;
    }

    destFD = open(argv[2], O_WRONLY | O_CREAT, 0777);
    if (destFD == -1){
        printf("\nERROR IN OPENING FILE");
        return 1;
    }

    while ((nbread = read(srcFD, buff, BUFF_SIZE)) > 0){
        if (write(destFD, buff, nbread) != nbread){
            printf("\nERROR I WRITING DATA TO %s\n", argv[2]);
            exit(1);
        }

        if (nbread == -1){
            printf("\nERROR IN READING DATA FROM %s\n", argv[1]);
            exit(1);
        }
    }
    close(srcFD);
    close(destFD);
    exit(0);
}