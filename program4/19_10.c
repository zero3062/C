#include <stdio.h>
#include <string.h> /*etrerror함수를 정의하는 헤더 파일*/
#include <stdlib.h>

int main()
{
	int i;

	/*오류 번호 1~124에 대한 설명 출력*/
	for(i=0; i<125; i++)
		printf("[%3d] %s\n", i, strerror(i));
	exit(0);
}
