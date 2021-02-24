#include <stdio.h>

int func();

int main()
{
	int i;
	i = func();
	printf("%d\n", i);
}

int func()
{
	return 5 + 7;
}
