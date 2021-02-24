#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *arg[] = {"ls", (char *)0};
	printf("Running ls with execvp\n");
	/*첫 번재 인수가 파일 이름이고 명령라인 인수는 인수들의 배열.
	  프로그램 ls는 PATH 환경 변수에 의해 지정된 디렉토리에서 찾음*/
	execvp("ls", arg);
	printf("execvp failed to run ls\n");
	exit(0);
}
