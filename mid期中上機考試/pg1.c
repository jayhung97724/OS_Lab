#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "rand4.h"
#define NUM_THREADS 4
#define ARR_LENHGTH 2000000
void findMax(){
	int max = -1;
	int i;
	for(i = 0; i < ARR_LENHGTH; i++){
		if (arr[i] > max)
			max = arr[i];
	}
	printf("MAX: %d\n", max);
}

int main(){

	struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    gettimeofday(&start,NULL);
    
 	findMax();

    gettimeofday(&end,NULL);
    diff = end.tv_usec-start.tv_usec;
    printf("Time interval: %ld\n",diff);
	return 0;
}