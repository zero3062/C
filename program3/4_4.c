#include <stdio.h>

int main()
{
	int i = 10;
	int *ptr;

	ptr = &i;
	(*ptr)++;
	printf("%d\n", i);
}
