#include <stdio.h>
#include <stdlib.h> /* abort함수를 정의하는 헤더 파일*/

int main()
{
	abort(); /*코어 덤프하고 프로그램 종료*/
	/*이후 문장이 실행되지 않음*/
	printf("not run\n");
}
