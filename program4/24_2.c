#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
	sigset_t set;

	/*모든 시그널을 포함하는 시그널 집합 set생성*/
	if(sigfillset(&set) == -1) {
		perror("sigfillset failed");
		exit(1);
	}
	/*set에서 SIFPIPE 삭제*/
	if(sigdelset(&set, SIGPIPE) == -1) {
		perror("figdelset failed");
		exit(1);
	}
	/*SIGPIPE가 set에 속하는지를 확인*/
	if(sigismember(&set, SIGPIPE))
		printf("SIGPIPE is a member\n");
	else 
		printf("SIFPIPE is noe a member\n");
	exit(0);
}
