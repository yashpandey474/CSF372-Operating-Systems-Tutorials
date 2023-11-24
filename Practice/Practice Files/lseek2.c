#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    int fd = open("txt1.txt", O_WRONLY);

    int ret = lseek(fd, 2, SEEK_END);

    char buf[30];

    write (fd, "tutorial", 3);

    // printf("%s %d", buf, ret);
}