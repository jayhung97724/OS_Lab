#include <stdio.h>
#include <unistd.h>

int global = 10;

int main() {

	int local = 10;
	printf("----------This is parent process----------\n");
	printf("Golbal:     %d  ", global);
	printf("Local:      %d  ", local);
	printf("Pid:        %d\n", getpid());
	
	pid_t new_pid;
	new_pid = fork();

	switch(new_pid) {
	    case -1:
		printf("fork error!\n");
		break;
	    case 0: // create a child process
		printf("----------This is child process----------\n");
		printf("Golbal:     %d  ", global);
		printf("Local:      %d  ", local);
		printf("Pid:        %d  ", getpid());
		printf("Parent Pid: %d\n", getppid());
		global++;
		local++;
		break;
	    default:
		wait();
		break;
	}
	switch(new_pid) {
	    case -1:
		printf("fork error!\n");
		break;
	    case 0:
		printf("----------Still in child process----------\n");
		printf("Golbal:     %d  ", global);		
		printf("Local:      %d  ", local);
		printf("Pid:        %d  ", getpid());
		printf("Parent Pid: %d\n", getppid());
		break;
	    default:
		printf("----------Back to parent process----------\n");
		printf("Golbal:     %d  ", global);
		printf("Local:      %d  ", local);
		printf("Pid:        %d\n", getpid());
		wait();
		break;
	}
	return 0;
}
