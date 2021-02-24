#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Running ls with execlp\n");
	/*첫 번재 인수가 파일 이름이고 명령라인 인수들을 나열.
	  프로그램 ls는 PATH 환경 변수에 의해 지정된 디렉토리에서 찾음*/
	execlp("ls", "ls", (char *)0);
	/*이후 문장은 실행되지 않음*/
	printf("execlp failed to run ls\n");
	exit(0);
}
