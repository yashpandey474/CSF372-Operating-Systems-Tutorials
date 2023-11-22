#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    //KEY_T OBJECT
    key_t key;


    //GENERATE
    key  = ftok("ftok", 1);

    //IF NOT GENERATED
    if (key == -1){
        printf("COULD NOT GENERATE\n");
        exit(1);
    }

    //GET MESSAGE QUEUE
    int msq_id = msgget(key, IPC_CREAT | S_IRUSR | S_IWUSR);

    if (msq_id == -1){
        printf("COULD NOT CREATE MESSAGE QUEUE\n");
        exit(1);
    }

    //SEND THE MESSAGE
    // msgsend(msq_id, &message, sizeof(message), 1, 0);''

    //REMOVE THE MESSAGE QUEUE
    // struct msgqid_ds* qbuf;
    // int ret = msgctl(msq_id, IPC_STAT, qbuf);
    
    // if (ret == -1){
    //     printf("COULD NOT REMOVE MESSAGE QUEUE");
    //     exit(1);
    // }

    printf("RECEIVED STRUCTURE: ");
    exit(0);
    
    }