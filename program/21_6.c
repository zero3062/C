#include <fcntl.h>

main()
{
	int fd;

	/* jkim 파일이 있으면 파일을 쓰기 전용으로 열어 0바이트로 자르고,
	   만약 없다면 0바이트 크기의 jkim을 생성하고 쓰기 전용으로 연다. */
	if((fd=open("jkim", O_WRONLY | O_CREAT | O_TRUNC, 0644))==-1) {
		perror("open failed");
		exit(1);
	}
	close(fd);
	exit(0);
}
