#include <stdio.h>

int main()
{
	FILE *fp;
	int ch='a';

	fp = fopen("source", "r");
	fputc(ch, fp);

	if(ferror(fp))
		puts("error");
	else 
		puts("no error");

	clearerr(fp);
	if(ferror(fp))
		puts("error");
	else
		puts("no error");

	fclose(fp);
}
