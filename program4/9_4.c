#include <stdio.h>
#include <stdlib.h> /*atof함수가 정의된 헤더파일*/

int main()
{
	/*소수점 형태의 문자열 "1.23"을 double형 실수로 변환한 값을 반환*/
	printf("%g\n", atof("1.23"));
	/*지수 형태의 문자열 "0.12E12"를 double형 실수로 변환한 값은 반환*/
	printf("%g\n", atof("0.12E12"));
	/*문자열 앞의 공백 문자는 무시하고, 부호도 처리하며 실수 형태의 문자까지만 처리*/
	printf("%g\n", atof("\t -367.177abc"));
}
