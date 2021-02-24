#include <stdio.h>
#include <stdlib.h> /*environ 변수를 선언하는 헤더 파일*/

/*environ에 환경 변수 정보 저장*/
extern char **environ;

int main()
{
	while(*environ)
		printf("%s\n", *environ++);
}
