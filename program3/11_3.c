#include <stdio.h>

int main()
{
	int i;
	float j;
	char str[10];

	printf("input integer, floating number, string ==> ");
	scanf("%d%f%s", &i, &j, str);
	printf("%d %f %s\n", i, j, str);
}
