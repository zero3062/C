#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd;

	/* 현재 디렉토리에 jkim 파일이 있으면 읽기 전용으로 열고,
	   없으면 현재 디렉토리에 0바이트 크기의 jkim을 생성하고 이를 연다.
	   생성된 파일의 접근 권한 정보는 0644 */
	if((fd=open("jkim",O_RDONLY | O_CREAT, 0644)) ==-1) {
		perror("open failed");
		exit(1);
	}
	close(fd);
	exit(0);
}
