#include <stdio.h>
main()
{
	int a, b, max, min;

	/* 두 개의 정수 입력 */
	printf("Input integer1 ==> ");
	scanf("%d", &a);
	printf("Input integer2 ==> ");
	scanf("%d", &b);
	/* a가 b보다 크면, 즉 조건 a>b가 참이면 실행한다. */
	if (a > b) {
		max = a;
		min = b;
	/* 그렇지 않으면, 즉 조건 a>b가 거짓이면 실행한다. */
	} else {
		max = b;
		min = a;
	}
	printf("max:%d\tmin:%d\n", max, min);
}
