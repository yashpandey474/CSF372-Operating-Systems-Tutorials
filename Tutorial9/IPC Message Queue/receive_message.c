#include <sys/stat.h>
#include <sys/msg.h>

#include <stdio.h>
#include <stdlib.h>


int main(void){

    //GET THE KEY
    key_t key = ftok("ftok", 65);

    //GET THE MESSAGE QUEUE IDENTIFIER
    int msq_id = msgget(key, 0666);

    //GET THE MESSAGE
    char buff[100];
    long msgtype;
    size_t msgsize;
    msgrcv(msq_id, &buff, msgsize, msgtype, IPC_NOWAIT);

    printf("MESSAGE RECEIVED: %s OF TYPE %d\n", buff, msgtype);

}