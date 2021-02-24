#include <stdio.h>
#include <stdlib.h> /*strtod함수가 정의된 헤더 파일*/

int main()
{
	char *pt;

	/*소수점 형태의 문자열 "1.23"을 double형 실수로 변환한 값을 반환*/
	printf("%g\n", strtod("1.23", NULL));
	/*지수 형태의 문자열 "0.12E12"를 실수로 변환한 값을 반환*/
	printf("%g\n", strtod("0.12E12", NULL));
	/*부호 지정 가능하고 실수 형태의 문자 '-367.177'까지만 처리하고 pt는
	  종료 지점인 'a'를 가리킴*/
	printf("%g ", strtod("\t-367.177abc", &pt));
	printf("%s\n", pt);
}
