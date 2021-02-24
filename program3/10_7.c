#include <stdio.h>
#include <string.h>

int main()
{
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	memmove(alphabet, alphabet+7, 19);
	printf("%s\n", alphabet);
}
