#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
	
	pid_t new_pid;
	new_pid = fork();

	switch(new_pid) {
	    case -1:
		printf("fork error!\n");
		break;
	    case 0: // create a child process
		printf("----------This is child process----------\n");
		printf("Pid:        %d  ", getpid());
		printf("Parent Pid: %d\n", getppid());
		
		break;
	    default:
		printf("----------This is parent process----------\n");
		printf("Pid:        %d\n", getpid());
		while(1){;}
		break;
	}
	return 0;
}
