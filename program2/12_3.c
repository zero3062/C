#include <stdio.h>
#include <math.h> /*ceil, floor, modf 함수가 정의된 헤더 파일*/

int main()
{
	double fra, itr;

	/*double형 데이터의 소수점 이하를 올림*/
	printf("%g\n", ceil(123.45));
	/*double형 데이터의 소수점 이하를 버림*/
	printf("%g\n", floor(345.67));

	/*double형 데이터를 정수부와 소수부로 분할하여 정수부는 itr에 저장하고
	  소수부는 반환되어 fra에 저장*/
	fra = modf(123.45, &itr);
	printf("%g, %g\n", itr, fra);
}
