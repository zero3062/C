#include <stdio.h>
#include <time.h> /*time, ctime 함수가 정의된 헤더 파일*/

int main()
{
	time_t time_now;

	/*1970년 1월 1일 0:00:00 UTC이후의 시간을 초 단위로 얻어와 time_now에 저장*/
	time (&time_now);
	/*time_t 형 시간 정보 time_now를 사용자가 알아보기 쉽게 문자열로 변환하여 출력*/
	printf("%s",ctime(&time_now));
}
