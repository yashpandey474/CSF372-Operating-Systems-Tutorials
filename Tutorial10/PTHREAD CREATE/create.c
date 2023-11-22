#include <stdio.h>
#include <pthread.h>


//THREAD'S MAIN FUNCTION
void* hello(void* input){
    printf("%s\n", (char*) input);
    pthread_exit(NULL);
}

int main(void){
    pthread_t tid;
    pthread_create(
        &tid,
        NULL,
        hello,
        "HELLO WORLD"
    );
    pthread_join(tid, NULL);
    return 0;
}