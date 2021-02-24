#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	/*SIGINT 시그널을 받으면 무시하도록 설정*/
	signal(SIGINT, SIG_IGN);
	while (1) {
		printf("Hello World\n");
		/*1초 동안 정지*/
		sleep(1);
	}
}
