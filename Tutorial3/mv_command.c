#include <stdio.h>
#include <fcntl.h>

int main(int argc, char * argv[]){
    int fd1, fd2, count;
    char buf[512];

    if (argc != 3){
        printf("INSUFFICIENT FILENAMES");
        exit(1);
    }

    fd1 = open(argv[1], O_RDONLY);

    if (fd1 == -1){
        printf("SOURCE FILE DOES NOT EXIST");
        exit(1);
    }

    fd2 = open(argv[2], O_WRONLY);
    if (fd2 == -1){
        fd2 = creat(argv[2], 0666);
    }

    while ((count = read(fd1, buf, 512)) > 0){
        write(fd2, buf, count);
    }

    close(fd2);
    close(fd1);

    int c = unlink(argv[1]);

    if (c != 0){
        printf("LINK ERROR");
        return 1;
    }
    printf("UNLINKED SUCCESSFULLY");
    
}

