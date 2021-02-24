#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 10

int main()
{
	int fd;
	char buf1[MAX], buf2[MAX];

	if((fd=open("alphabet", O_RDONLY))==-1) {
		perror("open failed");
		exit(1);
	}
	read(fd, buf1, MAX);

	read(fd, buf2, MAX);
	printf("buf1[0]: %c\nbuf2[0]: %c\n", buf1[0], buf2[0]);
	close(fd);
	exit(0);
}
