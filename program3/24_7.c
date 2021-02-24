#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	struct sigaction act;

	act.sa_handler = SIG_IGN;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGINT, &act, NULL);

	while(1) {
		printf("Hello World\n");
		sleep(1);
	}
}
