#include <stdio.h>

int main()
{
	FILE *fp;
	int ch;

	fp = fopen("source", "r");

	ch = fgetc(fp);
	ch = fgetc(fp);
	printf("%ld\n", ftell(fp));

	rewind(fp);
	printf("%ld\n", ftell(fp));

	fclose(fp);
}
