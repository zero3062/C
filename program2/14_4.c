#include <stdio.h>
#include <time.h> /*time, localtime, asctime, strftime 함수가 정의된 헤더 파일*/
#define SIZE 124

int main()
{
	time_t time_now;
	struct tm *tm_local;
	char buf[SIZE];

	/*1970년 1월 1일 00:00:00 UTC 이후의 시간을 초 단위로 얻어와 time_now에 저장*/
	time(&time_now);
	/*time_t형 시간 정보 time_now를 struct tm형 지역 시간 정보로 변환해서 tm_local에 저장*/
	tm_local = localtime(&time_now);

	/*struct tm형 시간 정보 tm_local을 문자열로 변환해서 출력*/
	printf("%s", asctime(tm_local));

	/*struct tm형 시간 정보 tm_local을 서식을 갖춘 시간 정보로 변환하는데,
	  변환 문자열 %c는 지역 날짜와 시간을 의미*/
	strftime(buf, sizeof(buf), "%c", tm_local);
	printf("%s\n",buf);
}
