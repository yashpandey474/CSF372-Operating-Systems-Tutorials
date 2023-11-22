#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int sum = 0;
    int i;

    if (argc != 4) {
        printf("invalid argument\n");
        exit(0);
    }
    for (i = 0; i < argc; i++){
        sum = sum + atoi(argv[i]);
    }
    printf("sum = %d\n", sum);
}