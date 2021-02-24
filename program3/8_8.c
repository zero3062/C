#include <stdio.h>
#include <string.h>

int main()
{
	char *ptrstr;

	ptrstr = strdup("Hello Linux");
	printf("%s\n", ptrstr);
}
