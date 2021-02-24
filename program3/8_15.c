#include <stdio.h>
#include <string.h>

int main()
{
	char str[]="Hello Linux C Programming";
	char delim[]="";
	char *ptr;

	ptr = strtok(str, delim);
	printf("%s\n", ptr);

	while(ptr==strtok(NULL, delim))
		printf("%s\n", ptr);
}
