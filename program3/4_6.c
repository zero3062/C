#include <stdio.h>

int main()
{
	char *str;

	str = "Hello";
	for(;*str;str++)
		printf("%s\n", str);
}
