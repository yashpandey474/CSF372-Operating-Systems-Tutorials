#include <sys/msg.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mesg_buffer{
    long mesg_type;
    char mesg_text[100];
} message, message1;

int main(){
    key_t key;
    int msqid;

    key = ftok("ftok", 65);

    //CREATE A QUEUE AND GET ITS ID
    msqid = msgget(key, 0666 | IPC_CREAT);

    //SET THE MESSAGE TYPE
    message.mesg_type = 1;

    //CREATE TUE TEXT
    // strcpy(message.mesg_text, "HELLO, RECEIVER");
    gets(message.mesg_text);

    //SEND THE MESSAGE
    msgsnd(
        msqid, //ID OF MESSAGE QUEUE
        &message, //POINTER TO MESSAGE OBJECT [ANY TYPE]
        sizeof(message), //SIZE OF MESSAGE
        0 //NO FLAGS
    );

    //RECEIVE THE MESSAGE
    msgrcv(
        msqid, //QUEUE IDENTIFIER
     &message1, //MESSAGE OBJECT
      sizeof(message1),//SIZE OF MESSAGE
       1, //MESSAGE TYPE DEFAULT
       0 //NO MESSAGE FLAG
       );

    printf("DATA SENT: %s\n", message.mesg_text);
    exit(0);


}