#include <stdio.h>

void func(void);

/*외부 정적 변수 count 선언*/
static int count=0;

int main()
{
	int i;
	
	for(i=0; i<10; i++)
		func();
	printf("count: %d\n", count);
}
