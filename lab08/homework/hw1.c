// 傳遞多個參數給thread handler  參考:http://pccts.blogspot.tw/2007/11/pthreadcreate.html

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS     4

int count = 0;

void *PrintHello(void *arg)
{
  int i;
  printf("-----------------\n");
  printf("Thread: %d Thread ID: %lu\n",(int) arg,pthread_self());
  for (i = 0; i < 250000; i++)
  {
      count +=1;
  }
  pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;

  for(t=0; t<NUM_THREADS; t++){
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
    if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
    }
    rc = pthread_join(threads[t], NULL);
    if (rc){
       printf("ERROR; return code from pthread_join() is %d\n", rc);
       exit(-1);
    }
  }

  printf("\n\nThis is main program.\n");
  printf("value= %d\n", count);

  return 0;
}
