// gcc -o 3 lab10-3.c -pthread
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

int item=0;
void produce(void);
void consume(void);
sem_t sema;
int main(void){
        int i=0;
        sem_init(&sema,0,1);
        pthread_t id[20];
        pthread_create(&id[0],NULL,(void*)consume,NULL);
        pthread_create(&id[1],NULL,(void*)produce,NULL);
        pthread_create(&id[2],NULL,(void*)consume,NULL);
        pthread_create(&id[3],NULL,(void*)produce,NULL);
        pthread_create(&id[4],NULL,(void*)consume,NULL);
        pthread_create(&id[5],NULL,(void*)produce,NULL);
        pthread_create(&id[6],NULL,(void*)consume,NULL);
        pthread_create(&id[7],NULL,(void*)produce,NULL);
        pthread_create(&id[8],NULL,(void*)consume,NULL);
        pthread_create(&id[9],NULL,(void*)produce,NULL);
        pthread_create(&id[10],NULL,(void*)consume,NULL);
        pthread_create(&id[11],NULL,(void*)produce,NULL);
        pthread_create(&id[12],NULL,(void*)consume,NULL);
        pthread_create(&id[13],NULL,(void*)produce,NULL);
        pthread_create(&id[14],NULL,(void*)consume,NULL);
        pthread_create(&id[15],NULL,(void*)produce,NULL);
        pthread_create(&id[16],NULL,(void*)consume,NULL);
        pthread_create(&id[17],NULL,(void*)produce,NULL);
        pthread_create(&id[18],NULL,(void*)consume,NULL);
        pthread_create(&id[19],NULL,(void*)produce,NULL);
        for(i=0;i<20;i++){
                pthread_join(id[i],NULL);
        }
        pthread_exit(NULL);
}

void produce(void){
        sem_wait(&sema);
        if(item >= 0 && item <5){
                item++;
        }
        printf("Item count: %d\n", item);
        sem_post(&sema);
        pthread_exit(NULL);
}
void consume(void){
        sem_wait(&sema);
        if(item > 0 && item <=5){
                item--;
        }
        printf("Item count: %d\n", item);
        sem_post(&sema);
        pthread_exit(NULL);
}