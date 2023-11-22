#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
    execl("/sum", "sum", "100", "200", "300", NULL);
    printf("execl call unsuccessful");
}