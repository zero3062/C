#include <stdio.h>
#include <time.h> /*time 함수가 정의된 헤더 파일*/

int main()
{
	time_t time_now; /* time_t형읜 long int형임*/

	/*1970년 1월 1일 00:00:00 UTC이후의 시간을 초 단위로 언어와 time_now에 저장*/
	time(&time_now);
	printf("%ld\n", time_now);
}

