//PRACTICE LSEEK COMMAND
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(void){
    //OPEN THE FILE
    int fd1 = creat("test.txt", 0777);
    close(fd1);

    //WRITE TO FILE
    fd1 = open("test.txt", O_RDWR);
    write(fd1, "I LOVE BITS", 11);
    
    int ret = lseek(fd1, 0, SEEK_SET);

    //READ FROM FILE
    char buffer[11];
    ret = read(fd1, buffer,sizeof(buffer));

    printf("READ: %s\n", buffer);
    printf("RET: %d\n", ret);

    //SEEK TO BEGINNING
    // ret = lseek(fd1, 5, SEEK_SET);
    // read(fd1, buffer, sizeof(buffer));

    // printf("RET: %d\n", ret);
    // printf("READ: %s\n", buffer);

    //SEEK TO END
    ret = lseek(fd1, -12, SEEK_END);
    read(fd1, buffer, sizeof(buffer));

    printf("RET: %d\n", ret);
    printf("READ: %s\n", buffer);
}   
