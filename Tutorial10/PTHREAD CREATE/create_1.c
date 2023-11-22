#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
//PROCESS SYSTEM CALLS => UNISTD
#include <unistd.h>

void printids(const char *s) {
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();

    printf("%d %d\n", pid, tid);
}
int main(){
    pthread_t ntid;
    int err;

    err = pthread_create(
        &ntid, //STORE ID
        NULL, //ATTRIBUTES -> DEFAULT
        printids, //FUNCTION
        NULL //NO ARGUMENTS
        );

    if (err != 0){
        // err_exit(err, "can't create thread");
        exit(1);
    }

    sleep(1);
    exit(0);
}