#include <fcntl.h>

main()
{
	int fd;

	/* 현재 디렉토리에 jkim 파일이 있으면 open 함수 호출에 실패하여 -1을 반환하고
	   만약 없다면 현재 디렉토리에 jkim을 생성하고 읽기 전용으로 연다. */
	if((fd=open("jkim", O_RDONLY | O_CREAT | O_EXCL, 0644))==-1) {
		perror("open failed");
		exit(1);
	}
	close(fd);
	exit(0);
}
