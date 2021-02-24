#include <stdio.h>

int main()
{
	int ch='Z';

	do{
		printf("%c", ch--);
	} while(ch>='A');
	printf("\n");
}
