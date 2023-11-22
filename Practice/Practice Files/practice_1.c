#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main(void){
    char buff[100];
    int ret2, fd1, fd2;

    fd1 = open("F1.txt", O_WRONLY | O_CREAT, 0777);
    fd2 = open("F2.txt", O_WRONLY | O_CREAT, 0777);

    ret2 = write(fd1, "BITS PILANI", 11);
    if (ret2 > 0){
        dup2(fd2, 1);
        printf("OS TEST\n");
    }
    close(3);
    close(4);
    return 0;
}