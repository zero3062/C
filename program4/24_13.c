#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int signal_flag=0;
void signalHandler(int signo);

int main()
{
	struct sigaction act;

	/*부모 프로세스는 */
	if(fork()) {
		printf("parent process\n");
		act.sa_handler = signalHandler;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		/*SIGINT 에 대해 act 행동을 하도록 설정*/
		sigaction(SIGINT, &act, NULL);
		/*시그널이 도착할 때까지 실행 중단*/
		pause();
		if (signal_flag)
		printf("signal fired\n");
		exit(0);
	/*자식 프로세스는*/
	}else{
		sleep(5);
		/*부모 프로세스에 SIGINT 시그널 보냄*/
		kill(getppid(), SIGINT); /*getppid는 부모 프로세스의 프로세스 ID를 반환*/
		exit(0);
	}
}

void signalHandler(int signo)
{
	signal_flag = 1;
}

