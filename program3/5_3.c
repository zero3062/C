#include <stdio.h>

void func(void);

int count = 0;

int main()
{
	int i;

	for(i=0;i<10;i++)
		func();

	printf("count : %d\n", count);
}
