#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include "rand4.h"
#define NUM_THREADS 4
#define ARR_LENHGTH 2000000
#define PARTIAL      500000

int max = -1;
int i = 0;
int ind = 0;

void *findMaxofPart(void *part){
	for(i = 0 ; i < PARTIAL; i++){
		if (arr[ind] > max)
			max = arr[ind];
		ind ++;
	}
}

int main(){

	struct  timeval start;
    struct  timeval end;
    unsigned  long diff;
    pthread_t threads[NUM_THREADS];
    int rc[4];
    int j;
    gettimeofday(&start,NULL);
    
    for(j = 0; j < 4; j++){
    	rc[j] = pthread_create(threads + j, NULL, findMaxofPart, (void *)j);
    	rc[j] = pthread_join(threads[j], NULL);
    }

    gettimeofday(&end,NULL);
    diff = end.tv_usec - start.tv_usec;
    printf("MAX: %d\n", max);
    printf("Find NAX by threading is completed.\n");
    printf("Time interval: %ld\n",diff);
	return 0;
}