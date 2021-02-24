#include <stdio.h>
int sum(int i);

main()
{
	printf("%d\n", sum(10));
}

int sum(int i)
{
	return i+sum(i-1);
}
