#include <stdio.h>
int main()
{
	float i = 2.345;		/* i는 4바이트 크기로 표현된 실수 저장 */
	double j = 0.12E-3; 	/* j는 8바이트 크기로 표현된 실수 저장 */
	/* %f는 소수점 형식, %e는 지수 형식,  %g는 %f와 %e 중 짧고 보기 좋은 형식으로 출력 */
	printf("i : %f %e %g\n", i, i, i);
	printf("j : %f %e %g\n", j, j, j);
}
