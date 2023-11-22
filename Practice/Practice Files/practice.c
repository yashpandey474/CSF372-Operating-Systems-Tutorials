#include <stdio.h> 
#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd, counter;
    char buf[12] = "CODE_OS";
    char buf1[12] = "";

    fd = open("test.txt", O_RDONLY, 0777);

    read(fd, buf, 3);
    printf("%s\n", buf);
    write(1, buf, 7);

    
}