#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signo);

main()
{
	sigset_t set, oldset;
	struct sigaction act;

	act.sa_handler = signalHandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	/*SIGINT에 대해 act 행동을 하도록 설정*/
	sigaction(SIGINT, &act, NULL);

	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	/*SIGINT 시그널에 블록 설정*/
	sigprocmask(SIG_BLOCK, &set, &oldset);
	sleep(10);
	/*oldset의 시그널이 블록화된 시그널 집합으로 교체되는데
	  이 상황에서는 SIGINT 시그널에 대한 블록이 해제*/
	sigprocmask(SIG_SETMASK, &oldset, NULL);
	/*시그널이 도착할 때까지 실행을 중단*/
	pause();
	exit(0);
}

void signalHandler(int signo)
{
	printf("Hi! signal %d\n", signo);
}
