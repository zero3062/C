#include <fcntl.h>
#include <unistd.h>
#define MAX 10

main()
{
	int fd;
	char buf[MAX]="C Program";

	/* jkim 파일이 있으면 쓰기 전용으로 열고 읽기/쓰기 포인터가 파일의 끝을 가리키며,
	   만약 jkim 파일이 없으면 파일을 생성하고 쓰기 전용으로 연다. */
	if((fd=open("jkim", O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1) {
		perror("open failed");
		exit(1);
	}
	write(fd, buf, MAX);
	close(fd);
	exit(0);
}
