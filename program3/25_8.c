#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *write_fp;
	char buffer[256];

	if((write_fp=popen(argv[1], "w"))==NULL) {
		perror("popen failed");
		exit(1);
	}

	sprintf(buffer, "Linux C Programming\n");
	fprintf(write_fp, buffer, stdin);

	pclose(write_fp);
	exit(0);
}
