#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    printf("BEFORE FORK");

    system("ps");

    fork();

    printf("AFTER FORK");

    system("ps");

    return 0;
}