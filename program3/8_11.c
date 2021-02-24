#include <stdio.h>
#include <string.h>

int main()
{
	char *str="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ptr;

	ptr=strrchr(str,'A');
	printf("%s\n",ptr);
}
