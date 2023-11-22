//IMPLEMENT THE MV COMMAND IN C
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    //GET THE SOURCE FILE IN READ MODE
    int fd = open("txt1.txt", O_RDONLY);

    if (fd == -1){
        printf("COULD NOT OPEN SOURCE\n");
        return 1;
    }

    //GET DEST FILE IN WRITE MODE [CREATE]
    int fd1 = creat("txt2.txt", 0666);

    if (fd1 == -1){
        printf("COULD NOT CREATE NEW FILE\n");
        return 1;
    }

    //WRITE CONTENT TO DEST FILE
    char buff[256];
    while (read(fd, buff, sizeof(buff)) > 0){
        if (write(fd1, buff, sizeof(buff)) == -1){
            printf("COULD NOT WRITE TO DEST\n");
        }
    }

    //REMOVE OLD FILE
    unlink("txt1.txt");

    //CLOSE FDS
    close(fd);
    close(fd1);


}