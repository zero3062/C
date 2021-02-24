#include <stdio.h>
#include <time.h> /*time, localtime 함수가 정의된 헤더 파일*/

int main()
{
	time_t time_now;
	struct tm *tm;

	/*1970년 1월 1일 00:00:00 UTC 이후의 시간을 초 단위로 얻어와 time_now에 저장*/
	time(&time_now);
	/*time_t형 시간 정보 time_now를 struct tm형 지역 시간 정보로 변환해서 tm에 저장*/
	tm=localtime(&time_now);

	/*%02d로 지정하면 2자리에 10진 정수 형태로 출력하되 한 자리 수라서 앞자리가
	  비게 되면 0을 채움*/
	printf("%02d/%02d/%4d ", tm->tm_mon+1, tm->tm_mday, tm->tm_year + 1900);
	printf("%02d:%02d:%02d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
}
