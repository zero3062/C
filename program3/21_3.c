#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd;

	if((fd==open("jkim", O_RDONLY))==-1) {
		perror("open failed");
		exit(1);
	}
	close(fd);
	exit(0);
}
