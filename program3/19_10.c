#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;

	for(i=0;i<125;i++)
		printf("[%3d] %s\n", i, strerror(i));
	exit(0);
}
