#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;

	if((fd=open(argv[1], O_WRONLY))==-1) {
		perror("open failed");
		exit(1);
	}
	/*dup2를 이용하여 fd번 파일에 대한 새로운 파일 식별자 7을 부여받음 */
	if((dup2(fd, 7)) == -1) {
		perror("dup2 failed");
		exit(1);
	}
	if(lseek(7, 0, SEEK_END) == -1) {
		perror("lseek failed");
		exit(1);
	}
	write(7, " ABCD", 5);
	close(fd);
	exit(0);
}
