#include <stdio.h>
main()
{
	int i, fac, n;

	i = fac = 1;
	printf("Input numbber ==> ");
	scanf("%d", &n);
	/* i가 n보다 작거나 같으면 12라인 반복 실행 */
	while (i <= n) {
		/* 'fac = fac * i++'를 의미 */
		fac *= i++;
	}
	printf("%d factorial : %d\n", n, fac);
}
