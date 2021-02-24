#include <stdio.h>

void func(void);

/* 외부 변수 count 선언 */
int count = 0;

main()
{
	int i;
	
	for(i=0; i<10; i++)
		func();
	/* 외부 변수 count 사용 */
	printf("count : %d\n", count);
}

void func(void)
{
	/* 외부 변수 count 사용 */
	count++;
}
