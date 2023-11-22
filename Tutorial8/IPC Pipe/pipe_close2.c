#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    //ARRAY TO HOLD FILE DESCRIPTOS
    int fileDescs[2];

    //BUFFER TO HOLD DATA
    char buff[30];

    //INSTANTIATE PIPE
    pipe(fileDescs);

    //FORK
    switch(fork()){
        case -1: {
            printf("FORK FAILED");
        }

        case 0: {
            //CHILD PROCESS
            printf("CHILD PROCESS: %d\n", getpid());

            //CLOSE WRITING FILE DESCRIPTOR FOR CHILD
            if ((close(fileDescs[1])) == -1){
                printf("COULD NOT CLOE WRITING FILE DESCRIPTOR\n");
            }

            //READ FROM PIPE
            read(fileDescs[0], buff, sizeof(buff));

            //DISPLAY READ DATA
            printf("DATA READ BY CHILD: %s\n", buff);

            if ((close(fileDescs[0])) == -1){
                printf("COULD NOT CLOSE READING\n");
            }

            exit(EXIT_SUCCESS);
        }
        default: {
            printf("PARENT PROCES\n");

            if ((close(fileDescs[0])) == -1){
                printf("COULD NOT CLOSE READING");
            }

            if (write(fileDescs[1], "HELLO I AM YASH!!!!!!!!!!!", 21) != 21){
                printf("COULD NOT WRITE!\n");
            }

            printf("PARENT SUCCESSFULLY WRITE TO PIPE\n");

            close(fileDescs[1]);

            //WAIT FOR CHILD PROCESS
            wait(NULL);

            exit(EXIT_SUCCESS);
        }
    }
}