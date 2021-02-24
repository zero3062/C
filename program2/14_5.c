#include <stdio.h>
#include <time.h>  /*time, difftime 함수가 정의된 헤더 파일*/
#include <unistd.h> /*sleep 함수가 정의된 헤더 파일*/

int main()
{
	time_t old, new;

	/*초 단위의 현재 시간 얻기*/
	time(&old);
	/*5초 동안 정지하기*/
	sleep(5);
	time(&new);

	/*new 시간과 old 시간의 초 단위 시간차를 구함*/
	printf("%g\n", difftime(new, old));
}
