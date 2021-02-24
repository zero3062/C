#include <stdio.h>

int main()
{
	FILE *fp;
	int i;
	float j;
	char *str;

	fp = fopen("data", "w");
	fscanf(fp, "%d%g%s", &i, &j, str);
	printf("%d %g %s\n", i, j, str);
	fclose(fp);
}
