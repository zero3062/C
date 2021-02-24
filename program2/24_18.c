#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	sigset_t set1, set2;

	/*꽉 찬 시그널 집합 set1 생성*/
	sigfillset(&set1);
	sigemptyset(&set2);
	/*SIGINT를 원소로 하는 시그널 집합 set2*/
	sigaddset(&set2, SIGINT);

	/*모든 시그널에 블록 설정*/
	sigprocmask(SIG_BLOCK, &set1, NULL);
	printf("block start\n");
	sleep(10);
	/*SIGINT 시그널은 블록에서 해제*/
	sigprocmask(SIG_UNBLOCK, &set2, NULL);
	printf("SIGINT unblock\n");
	while(1) {
		printf("Hello World\n");
		sleep(2);
	}
}
