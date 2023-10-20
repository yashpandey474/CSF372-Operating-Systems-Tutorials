#include <stdio.h>
#include <fcntl.h>

int main(){
    //CREATE A DIRECTORY
    int md, fd1, fd2, ret;
    
    md = mkdir("exercise", 0777);

    if (md == 0){
        printf("DIRECTORY IS CREATED\n");
    }
    else{
        printf("UNABLE TO CREATE DIRECTORY");
        return 1;
    }

    //CREATE TWO TEXTFILES
    fd1 = creat("exercise/file1.txt", 0777);
    fd2 = creat("exercise/file2.txt", 0777);

    //WRITE TO ONE OF THE FILES

    //OPEN THE FILE
    fd1 = open("exercise/file1.txt", O_WRONLY);

    //WRITE TO FILE
    char buffer[9] = "TEST DATA";
    ret = write(fd1, buffer, sizeof(buffer));

    //COPY CONTENT TO OTHER FILE
    close(fd1);
    fd1 = open("exercise/file1.txt", O_RDONLY);
    fd2 = open("exercise/file2.txt", O_WRONLY);

    read(fd1, buffer, sizeof(buffer));
    write(fd2, buffer, sizeof(buffer));

    close(fd1);
    close(fd2);
    
}