#include <stdio.h>
#include <string.h>

int main()
{
	char *str = "Hello Linux Programming, Linuxer";
	char *ptr;

	ptr = strstr(str, "Linux");
	printf("%s\n", ptr);
}
