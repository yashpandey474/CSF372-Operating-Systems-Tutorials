#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(void){
    //THE ARRAY TO HOLD FILE DESCRIPTIONS
    int fileDescs[2];
    //BUFFER TO HOLD DATA
    char buff[30];

    //INSTANTIATE THE PIPE DESCRIPTOORS
    pipe(fileDescs);

    if (!fork()){
        //FOR CHILD PROCESS
        printf("CHILD PROCESS: %d\n", getpid());

        //WRITE DATA
        write(fileDescs[1], "DATA WRITTEN TO PIPE", 21);

        printf("CHILD PROCESS EXITING\n");
        exit(0);
    }
    else{
        //PARENT PROCESS
        printf("PARENT PROCESS: %d\n", getpid());

        //READ DATA FROM PIPE
        read(fileDescs[0], buff, 21);

        //DISPLAY DATA
        write(1, buff, 21);

        //WAIT FOR CHILD PROCESS [AVOID ZOMBIE PROCESS]
        wait(NULL);
    }

    return 0;
}