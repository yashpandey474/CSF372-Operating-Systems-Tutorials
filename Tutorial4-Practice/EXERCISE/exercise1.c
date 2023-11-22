#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(){
    //MAKE A DIRECTORY
    int ret = mkdir("tmp", 0777);

    //OPEN THE DIRECTORY AS A DIRECTORY STREAM
    DIR* ds = opendir("tmp");

    //CREATE TWO TEXT FILES IN DIRECTORY
    int fd1 = creat("tmp/abc.txt", 0666);
    int fd2 = creat("tmp/123.txt", 0666);

    //WRITE SOME CONTENT INTO FIRST FILE
    if (write(fd1, "THIS IS CONTENT!", 15) == -1){
        printf("COULD NOT WRITE CONTENT\n");
        exit(1);
    }

    //CLOSE AND REOPEN FOR READING
    close(fd1);
    close(fd2);
    fd1 = open("tmp/abc.txt", O_RDONLY);
    fd2 = open("tmp/123.txt", O_WRONLY);
    //READ FROM FIRST FILE
    char ch[1];
    while((read(fd1, ch, 1)) == 1){
        if (write(fd2, ch, 1) == -1){
            printf("COULD NOT WRITE CONTENT\n");
            exit(1);
        }
    } 

    //CLOSE THE FILES
    close(fd1);
    close(fd2);
    closedir(ds);

}