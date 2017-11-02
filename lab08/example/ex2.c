/*
  This version will occur Race condition
  ex3.c can overcome this problem
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;

void *PrintHello(void *arg)
{
  int i;
  printf("-----------------\n");
  printf("Thread: %d Thread ID: %lu\n",(int) arg,pthread_self());
  for (i = 0; i < 2500000; i++)
  {
      count +=1;
  }
  pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
  pthread_t thread1, thread2, thread3, thread4;
  int rc, rc2, rc3, rc4;
  long t;

  rc = pthread_create(&thread1, NULL, PrintHello, (void *)1);

  rc2 = pthread_create(&thread2, NULL, PrintHello, (void *)2);

  rc3 = pthread_create(&thread3, NULL, PrintHello, (void *)3);

  rc4 = pthread_create(&thread4, NULL, PrintHello, (void *)4);

  rc = pthread_join(thread1, NULL);
  rc2 = pthread_join(thread2, NULL);
  rc3 = pthread_join(thread3, NULL);
  rc4 = pthread_join(thread4, NULL);


  printf("\n\nThis is main program.\n");
  printf("value= %d\n", count);

  return 0;
}
