#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void){
    char buffer[12] = "I LOVE BITS";

    int fd1, ret;

    //CREATE A NEW FILE
    fd1 = creat("test.txt", 0777);

    //USE THE FD RETURNED ON CREATION FOR WRITING
    write(fd1, buffer, sizeof(buffer));

    //CLOSE THE FD
    close(fd1);

    exit(0);
}