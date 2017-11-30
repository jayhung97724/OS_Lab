#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFFER_SIZE 5
#define SIZE 4

int out = 0;
int in = 0;

int buffer[BUFFER_SIZE];
sem_t mutex;
sem_t emptyBuffer;
sem_t fullBuffer;

void *producer(void *param)
{
        int item,i;
        for(i = 0;i < SIZE;i++)
        {
                sem_wait(&emptyBuffer);
                sem_wait(&mutex);
                printf("Inpud send number:\n");
                scanf("%d",&item);
                fflush(stdin);
                buffer[in] = item;
                in = (in + 1) % BUFFER_SIZE;
                printf("in:%d producer[%d] send : %d\n",in,(int)param,item);
                fflush(stdout);
                sem_post(&mutex);
                sem_post(&fullBuffer);
               // if(i%2 ==1) sleep(1);
        }
        pthread_exit(NULL);
}

void *consumer(void *param)
{
        int item,i;
        for(i=0;i<SIZE;i++)
        {
                sem_wait(&fullBuffer);
                sem_wait(&mutex);
                item = buffer[out];
                out = (out+1) % BUFFER_SIZE;
                printf("out:%d consumer[%d] received : %d\n",out,(int)param,item);
                fflush(stdout);
                sem_post(&mutex);
                sem_post(&emptyBuffer);
                //if(i%2 ==1) sleep(1);
        }
        pthread_exit(NULL);
}
int main()
{
        int i,j,c=0;
        pthread_t pro[3],con[3];
        sem_init(&mutex,0,1);
        sem_init(&emptyBuffer,0,5);
        sem_init(&fullBuffer,0,0);

        for(i=0;i<3;i++)
        {
                //c++;
                //printf("%d\n",c);
                j = pthread_create(&pro[i],NULL,producer,(void*)i);
                if(j!=0)
                {
                        printf("Unable to create producer thread\n");
                        return -1;
                }
        }
        for(i=0;i<3;i++)
        {
                j = pthread_create(&con[i],NULL,consumer,(void*)i);
                if(j!=0)
                {
                        printf("Unable to create consumer thread\n");
                        return -1;
                }
        }
        pthread_exit(NULL);
}
                                                                                                                                                             13,1         頂端
  
