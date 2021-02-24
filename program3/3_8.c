#include <stdio.h>

int main()
{
	int i, j;
	i=(j=3, j+4);
	printf("%d %d\n", i, j);
}
