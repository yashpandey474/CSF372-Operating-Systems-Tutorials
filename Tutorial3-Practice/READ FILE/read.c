#include <stdio.h>
//FOR OPEN/CREAT: FCNTL
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
//FOR READ AND WRITE: UNISTD
#include <unistd.h>


int main(void){
    //OPEN THE FILE FIRST
    int fd = open("txt1.txt", O_RDONLY | O_CREAT, 0666);

    //READ INTO A BUFFER
    char buff[30];

    read(fd, buff, sizeof(buff));

    //WRITE TO STDOUT
    write(1, buff, sizeof(buff));
}
