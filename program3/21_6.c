#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd;

	if((fd=open("jkim", O_WRONLY | O_CREAT | O_TRUNC, 0644))==-1) {
		perror("open failed");
		exit(1);
	}
	close(fd);
	exit(0);
}
