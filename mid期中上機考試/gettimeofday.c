#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
 
int delay(int time)
{
    int i,j;
   
    for(i =0;i<time;i++)
        for(j=0;j<5000;j++)
            ;
}
 
int main()
{
        struct  timeval start;
        struct  timeval end;
       
        unsigned  long diff;
        gettimeofday(&start,NULL);
        delay(10);
        gettimeofday(&end,NULL);
        diff = end.tv_usec-start.tv_usec;
        printf("the difference is %ld\n",diff);
        return 0;
       
}