#include <stdio.h>
int sum(int i);

int main()
{
	printf("%d\n", sum(0));
}

int sum(int i)
{
	return i+sum(i-1);
}
