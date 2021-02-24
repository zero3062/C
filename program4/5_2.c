#include <stdio.h>

void func(void);

/*외부 변수 count 선언*/
int count = 0;

int main()
{
	int i;

	for(i=0; i<0; i++)
		func();
	/*외부 변수 count사용*/
	printf("count : %d\n", count);
}

void func(void)
{
	/*외부 변수 count사용*/
	count++;
}
