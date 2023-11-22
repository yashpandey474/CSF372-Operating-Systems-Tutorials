//OPEN SYSTEM CALL
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main(){
    int fd1, fd2;

    //OPEN THE FIRST FILE
    fd1 = open(
        "txt1.txt", //FILENAME
         O_WRONLY | O_CREAT, //FLAGS
          0777 //MODE
          );

    //OPEN SECOND FILE
    fd2 = open(
        "txt2.txt",
        O_WRONLY | O_CREAT,
        0777
    );

    //CLOSE THE FILES
    int ret = dup2(fd1, 1);

    if (ret == -1){
        printf("ERROR\n");
    }
    printf("HELLO\n");
    printf("FD1 = %d FD2 = %d\n", fd1, fd2);
    close(fd1);
    close(fd2);
}