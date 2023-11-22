#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if (vfork() || vfork() ){
        printf("P");
    }
    else{
        printf("C");
    }
    exit(0);
}