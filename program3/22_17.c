#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(symlink(argv[1], argv[2]) == -1) {
		perror("symlink failed");
		exit(1);
	}
	printf("link %s to %s\n", argv[1], argv[2]);
	exit(0);
}
