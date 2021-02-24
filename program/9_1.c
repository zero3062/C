#include <stdio.h>

main()
{
	int i;

	/* "23"과 "567"은 정수가 아닌 문자열이므로 + 연산 불가 */
	i = "23" + "567";
	printf("%d\n", i);
}
