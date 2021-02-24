#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	FILE *fp;

	if((fp=fopen("nodata", "r"))==NULL) {
		printf("errno = %d\n", errno);
		exit(1);
	}
	exit(0);
}
