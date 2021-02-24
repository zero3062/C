#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat st;

	for(i=1; i<argc; i++) {
		if(stat(argv[i], &st) == -1) {
			perror("stat failed");
			exit(1);
		}
		printf("%s's mode : %x\n", argv[2], st.st_mode);
	}

	exit(0);
}
