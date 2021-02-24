#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd;
	char buf[20]="Linux C Programming";

	/* newfile이 있으면 쓰기 전용으로 열고, 없으면 newfile을 생성하여 연다. */
	if((fd=open("newfild", O_WRONLY |  O_CREAT, 0644)) == -1) {
		perror("open failed");
		exit(1);
	}
	/* fd 파일에 buf에 있는 20바이트 데이터 쓰기 */
	if(write(fd, buf, 20) == -1) {
		perror("write failed");
		exit(1);
	}
	close(fd);
	exit(0);
}
