#include <stdio.h>
#include <stdlib.h>	/* abs, labs 함수가 정의된 헤더 파일 */
#include <math.h> /* fabs 함수가 정의된 헤더 파일 */

main()
{
	/* int형 데이터의 절대값 구하기 */
	printf("%d : %d\n", -345, abs(-345));
	/* long형 데이터의 절대값 구하기 */
	printf("%ld : %ld\n", -123456789, labs(-123456789));
	/* double형 데이터의 절대값 구하기 */
	printf("%g : %g\n", -23.456, fabs(-23.456));
}
