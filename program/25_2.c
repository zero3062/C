#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

main(int argc, char *argv[])
{
	int fd;
	struct flock filelock;

	filelock.l_type = (!strcmp(argv[1], "r"))?F_RDLCK:F_WRLCK;
	/*파일 전체를 영역으로*/
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 0;

	fd = open(argv[2], O_RDWR);	/* argv[2] 파일 열기*/

	/*fd 파일에 대해 filelock 형태로 레코드 잠금을 설정. 설정에 실패하면 -1을 반환*/
	if(fcntl(fd, F_SETLK, &filelock) == -1) {
		perror("fcntl failed");
		exit(1);
	}
	printf("success\n");
	exit(0);
}
