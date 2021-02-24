#include <stdio.h>
#include <stdlib.h> /*div, ldiv 함수가 정의된 헤더 파일*/
#include <math.h> /*fmod함수가 정의된 헤더 파일*/

int main()
{
	div_t result1;
	ldiv_t result2;

	/*int형 나눗셈의 몫과 나머지를 구해 반환한 값이 result에 저장되는데
	  result1.quot에 몫이 저장되고 result1.rem에 나머지가 저장된다.*/
	result1 = div(12345, 2345);
	/*long형 나눗셈의 몫과 나머지 구하기*/
	result2 = ldiv(123456789,12345678);

	/*result1.quot는 몫, result1.rem은 나머지를 의미*/
	printf("%d, %d\n", result1.quot, result1.rem);
	printf("%ld, %ld\n", result2.quot, result2.rem);
	/*double형 나눗셈의 나머지 구하기*/
	printf("%g\n", fmod(23.456, 2.345));
}
