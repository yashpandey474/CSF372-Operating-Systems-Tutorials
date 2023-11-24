#include <stdio.h> 
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
int fp, counter;
char charac[100];
    fp = open("bits2.txt", O_RDWR | O_CREAT);
    write(fp, "operating systems", 5);
    lseek(fp, 0, SEEK_END);
    write(fp, "tutorial", 3);
    lseek(fp, 0, 0);
    counter = read(fp, charac, 100);
    printf("%s\n", charac);
    return 0;
}