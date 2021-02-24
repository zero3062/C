#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;


	if((fd=open(argv[1], O_WRONLY))==-1) {
		perror("open failed");
		exit(1);
	}
	/* 읽기/쓰기 포인터가 파일의 끝으로 이동 */
	if((lseek(fd, 0, SEEK_END))==-1) {
		perror("lseek failed");
		exit(1);
	}
	/* 쓰기를 하면 파일의 뒤에 연결 */
	write(fd, " ABCD", 5);
	close(fd);
	exit(0);
}
