#include <signal.h>
#include <unistd.h>
#include <stdio.h>

struct sigaction act;
void handler1() {
	printf("How are you?\n");
}

void handler2() {
	printf("I am fine!\n");
}

void dohandler2() {
	act.sa_handler = SIG_DFL;
	sigaction(SIGINT, &act, NULL);
}

void dohandler1() {
	act.sa_handler = handler2;
	sigaction(SIGINT, &act, NULL);
	signal(SIGALRM, dohandler2);
	alarm(3);
	
}


int main() {

	act.sa_handler = handler1;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	sigaction(SIGINT, &act, NULL);
	signal(SIGALRM, dohandler1);
	alarm(3);
	while(1);
}