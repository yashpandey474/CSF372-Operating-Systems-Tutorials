#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* trythis(void* arg){
    pthread_mutex_lock(&lock);
    

    unsigned long i = 0;

    counter += 1;

    printf("JOB %d STARTED\n", counter);

    for(i = 0; i < 100; i ++){
        continue;
    }

    printf("JOB %d HAS FINISHED\n", counter);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void){
    int i = 0; int error;

    if (pthread_mutex_init(&lock, NULL) != 0){
        return 1;
    }

    while (i < 2){
        error = pthread_create(&(tid[i]),
        NULL, &trythis, NULL);

        if (error != 0){
            return 1;
        }
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
}