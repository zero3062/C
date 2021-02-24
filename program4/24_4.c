#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	/*SIGNAL 시그널을 받으면 무시하도록 설정*/
	signal(SIGINT, SIG_IGN);
	while(1){
		printf("Hello World\n");
		sleep(1); /*1초 동안 정지*/
	}
}
