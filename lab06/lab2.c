#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	// create process B
	if(fork() == 0)
	{
		// create process C
		if(fork() == 0)
		{
		    	printf("I'm child process C.\n");
		    	printf("Pid:        %d  ", getpid());
			printf("Parent Pid: %d\n", getppid());
		    	return 0;
		}
		wait(NULL);

		printf("I'm child process B.\n");
		printf("Pid:        %d  ", getpid());
		printf("Parent Pid: %d\n", getppid());
		return 0;
	}
	wait(NULL);

	// create process D
	if(fork() == 0)
	{
		printf("I'm child process D.\n");
		printf("Pid:        %d  ", getpid());
		printf("Parent Pid: %d\n", getppid());
		return 0;
	}
	wait(NULL);

	// create process E
	if(fork() == 0)
	{
		printf("I'm child process E.\n");
		printf("Pid:        %d  ", getpid());
		printf("Parent Pid: %d\n", getppid());
		return 0;
	}
	wait(NULL);

	printf("I'm parent process A\n");
	printf("Pid:        %d\n", getpid());
	return 0;
}
