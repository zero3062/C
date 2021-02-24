#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd, newfd;

	if((fd = open(argv[1], O_WRONLY)) == -1) {
		perror("open failed");
		exit(1);
	}
	/*fd 파일에 대한 새로운 파일 식별자를 부여받아 newfd에 저장*/
	if((newfd=dup(fd)) == -1) {
		perror("dup failed");
		exit(1);
	}
	if(lseek(newfd, 0, SEEK_END) == -1) {
		perror("lseek failed");
		exit(1);
	}
	write(newfd, " ABCD", 5);
	close(fd);
	exit(0);
}
