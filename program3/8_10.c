#include <stdio.h>
#include <string.h>

int main()
{
	char *str="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ptr;

	ptr = strchr(str, 'K');
	printf("%s\n", ptr);
}
