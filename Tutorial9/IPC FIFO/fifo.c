#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    //HOLD THE FIFO FILE DESCRIPTOOR
    int fd;

    char arr1[80];
    char arr2[80];

    //CREATE THE FIFO IN A FILE
    mkfifo("/tmp/myfifo", 0777);

    //CONTINOUSLY OPEN THE FILE AND RWRITE/READ
    int i = 0;
    while (i<5){
        i += 1;
        //OPEN THE FIFO USING A FD
        fd = open("/tmp/myfifo", O_WRONLY);

        //WRITE TO FILE
        write(fd, "HELLO! THIS WAS WRITTEN", 20);

        //CLOSE
        close(fd);

        //OPEN FOR READING
        fd = open("/tmp/myfifo", O_RDONLY);

        //READ FROM FILE
        read(fd, arr1, 20);

        printf("DATA READ: %s\n", arr1);
        close(fd);
    }
}