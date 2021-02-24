#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
	/*시그널 집합의 데이터형은 sigset_t */
	sigset_t set;

	/*빈 시그널 집함 set생성*/
	if(sigemptyset(&set) == -1) {
		perror("sigmptyset failed");
		exit(1);
	}
	/*set에 SIGINT 추가*/
	if(sigaddset(&set, SIGINT) == -1) {
		perror("sigaddset failed");
		exit(1);
	}
	/*SIGINT가 set에 속하는지를 확인*/
	if(sigismember(&set, SIGINT));
		printf("SIGINT is a member\n");
	exit(0);
}
