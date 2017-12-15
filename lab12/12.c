#include <stdio.h>
#include <stdlib.h>

char logical_mem[12];
char phy_mem[32];
int page_table[6];
int free_frame_list[16] ;
int i, j;
void print(){
	printf("****Logical memory*****\n");
	printf("----Page/Entry----Data----\n");
	for(i=0; i<12; i++){
		printf("-\t%d\t%d\t%c\n", (int)i/2, i%2, logical_mem[i]);
	}
	printf("\n******Page Table******\n");
	printf("Process 0:\n");
	printf("=================\n");
	printf("-----Page-----Frame-----\n");
	for(i=0; i<3; i++)
		printf("-\t%d\t%d\n", i, page_table[i]);
	printf("Process 1:\n");
	printf("=================\n");
	printf("-----Page-----Frame-----\n");
	for(i=3; i<6; i++)
		printf("-\t%d\t%d\n", i, page_table[i]);
	printf("\n****Physical memory****\n");
	printf("-----Frame/Entry-----Data----\n");
	for(i=0; i<32; i++){
		printf("-\t%d\t%d\t%c\n", (int)i/2, i, phy_mem[i]);
	}
}
void initialize(){
	printf("initialization....\n");
	for(i=0; i<6; i++){
		page_table[i] = -1;
	}
	for(i=0; i<12; i++){
		logical_mem[i] = '?';
	}
	for(i=0; i<32; i++){
		phy_mem[i] = '?';
	}
	for(i=0; i<16; i++){
		free_frame_list[i] = 0;
	}
	print();
}
void paging(){
	printf("\n\n================\nPaging..........\n");
	for (i = 0; i < 12; i++)
	{
		logical_mem[i] = (char) i+65;
	}
	int rand_int = 0;
	i = 0;
	while(i<6){
		rand_int = rand()%16;
		// printf("%d\n", rand_int);
		// printf("%d\n", free_frame_list[rand_int]);
		if (free_frame_list[rand_int] == 0)
		{
			// printf("======\n%d\n", free_frame_list[rand_int]);
			free_frame_list[rand_int] = 1;
			page_table[i] = rand_int;
		}
		i++;
	}
	i = 0;
	for (i = 0; i < 6; i++)
	{
		printf("Process %d page(%d) ->frame(%d)\n", (int)i/3, i, page_table[i]);
		phy_mem[page_table[i]*2] = logical_mem[i*2];
		phy_mem[page_table[i]*2+1] = logical_mem[i*2+1];
	}
	print();
}
int main(){
	initialize();
	paging();
	
	return 0;
}
