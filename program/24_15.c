#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void alarmHandler(int signo);

main()
{
	int status;
	struct sigaction act;

	/*시그널에 대해 alarmHandler가 실행되도록 설정*/
	act.sa_handler = alarmHandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	/*SIGALRAM에 대해 act 행동을 하도록 설정*/
	act.sa_handler = alarmHandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	/*SIGALRM에 대해 act 행동을 하도록 설정*/
	sigaction(SIGALRM, &act, NULL);
	/*3초 후에 SIGALRM 시그너를 자신에게 보냄*/
	alarm(3);
	while(1)	/*무한 반복*/
		;
}

void alarmHandler(int signo)
{
	printf("Hi! signal %d\n", signo);
	exit(0);
}
