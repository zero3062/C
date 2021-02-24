#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
	sigset_t set;

	if(sigemptyset(&set)==-1) {
		perror("signemptyset failed");
		exit(1);
	}

	if(sigaddset(&set, SIGINT)==-1) {
		perror("sigaddsset failed");
		exit(1);
	}

	if(sigismember(&set, SIGINT)) 
		printf("SIGINT is a member\n");
	else 
		printf("SIGINT is not a member\n");
	exit(0);
}
