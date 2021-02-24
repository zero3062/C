#include <stdio.h>

void func(void);

main()
{
	int i;

	for(i=0; i<10; i++)
		fuc();
}

void func(void)
{
	int auto_var = 0;	/* 자동 변수 auto_var 선언 */
	static int stat_var = 0;	/* 내부 정적 변수 stat_var 선언 */

	/* 내부 정적 변수는 자동 변수와는 달리 함수를 벗어나도 값이 유지된다. */
	printf("auto: %d static: %d\n", ++auto_var, ++stat_var);
}
