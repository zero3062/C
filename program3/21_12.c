#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 1024

int main()
{
	int count;
	char buf[MAX];

	while((count=read(STDIN_FILENO, buf, MAX)) > 0) {
		if(write(STDOUT_FILENO, buf, count) != count) {
			perror("write failed");
			exit(1);
		}
	}
	exit(0);
}
