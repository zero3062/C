#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;

	if((fd = open(argv[1], O_WRONLY)) == -1) {
		perror("open filed");
		exit(1);
	}
	/*fd 파일을 100바이트 크기로 자름*/
	if(ftruncate(fd, 100) == -1) {
		perror("ftruncate failed");
		exit(1);
	}
	close(fd);
	exit(0);
}
