#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int *ptr;

	if((ptr=(int *)malloc(10))==NULL)
		exit(1);

	memset(ptr, 'a', 9);
	ptr[9] = '\0';

	printf("%ls\n", ptr);

	free(ptr);
}
