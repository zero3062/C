#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(remove(argv[1])==-1) {	
		perror("remove failed");
		exit(1);
	}
	printf("remove %s\n", argv[1]);
	exit(0);
}
