#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	FILE *fp;

	if((fp=fopen("nodta", "r"))==NULL) {
		fprintf(stderr, "ERROR: %s\n", strerror(errno));
		exit(1);
	}
	exit(0);
}
