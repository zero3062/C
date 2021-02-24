#include <stdio.h>
#include <stdlib.h>

/*명령라인 인수를 가져온다. argc에는 인수의 개수를 argv에는 인수의 내용을 저장한다.*/
int main(int argc, char *argv[])
{
	int i;

	printf("argc : %d\n", argc); /*인수의 개수 출력*/

	/*인수의 내용 출력*/
	for(i=0;i<argc;i++)
		printf("argv[%d] : %s\n", i, argv[i]);

	exit(0);
}
