#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 100	

int main()
{
	int fd, i;
	char buf[MAX];
	long int length = 0;

	if((fd==open("jkim", O_RDONLY))==-1) {
		perror("open failed");
		exit(1);
	}
	while((i=read(fd, buf, MAX)) > 0)
		length += i;
	printf("Total characters in jkim : %ld\n", length);
	close(fd);
	exit(0);
}
