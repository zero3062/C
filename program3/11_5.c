#include <stdio.h>

int main()
{
	FILE *fp;

	fp = fopen("jkim", "r");
	fclose(fp);
}
