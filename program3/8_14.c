#include <stdio.h>
#include <string.h>

int main()
{
	char *ptr;

	ptr = strpbrk("seoulKorea", "Ka");
	printf("%s\n", ptr);
}
