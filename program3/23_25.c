#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *str;
	int i=1;
	printf("Running %s with system\n", argv[1]);
	while(argc>i) {
		strcat(str, argv[i++]);
		strcat(str,"");
	}
	system(str);
	printf("Done\n");
	exit(0);
}
