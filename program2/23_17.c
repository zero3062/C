#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	/*인수 리스트를 내용으로 하는 문자열 배열*/
	char *arg[] = {"ls", (char *)0};
	printf("Running ls with execv\n");
	/*첫번째 인수가 경로 이름이고, 명령라인 인수는 인수들의 배열*/
	execv("/bin/ls", arg);
	printf("execv failed to run ls\n");
	exit(0);
}
