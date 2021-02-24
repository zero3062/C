#include <stdio.h>
#include <stdlib.h>

void func1(void);
void func2(void);
void func3(void);
void func4(void);

int main()
{
	/*exit함수 호출 때 실행딘 함수를 func1, func2, func3 순으로 등록*/
	atexit(func1);
	atexit(func2);
	atexit(func3);

	exit(0);
}

void func1(void)
{
	printf("run function1\n");
}

void func2(void)
{
	printf("run function2\n");
}

void func3(void)
{
	printf("run function3\n");
}
