#include <stdio.h>

int main()
{
	FILE *fp;
	int ch;

	fp = fopen("alphabet", "r");
	fseek(fp, 10, SEEK_SET);

	while((ch=fgetc(fp))!=EOF) 
		putchar(ch);

	fclose(fp);
}
