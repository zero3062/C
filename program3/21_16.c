#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 10

int main()
{
	int fd, count;
	char buf[MAX];

	if((fd=open("alphabet", O_RDONLY))==-1) {
		perror("open failed");
		exit(1);
	}
	lseek(fd, 5, SEEK_SET);
	count = read(fd, buf, MAX);
	write(STDOUT_FILENO, buf, count);
	close(fd);
	exit(0);
}
