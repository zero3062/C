#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

main(int argc, char *argv[])
{
	int fd;
	struct flock filelock;

	/*argv[1]의 내용이 "r"이면 F_RDLCK를, 아니면 F_WRLCK를 filelock.l_type에 저장*/
	filelock.l_type = (!strcmp(argv[1], "r"))?F_RDLCK:F_WRLCK;
	/*파일 전체를 영역으로*/
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 0;

	/*argv[2] 파일을 여는데, 없으면 생성*/
	fd = open(argv[2], O_RDWR | O_CREAT, 0666);

	/*fd 파일, 즉 argv[2]에 대해 filelock 형태로 레코드 잠금을 설정*/
	if(fcntl(fd, F_SETLK, &filelock) == -1) {
		perror("fcntl failed");
		exit(1);
	}
	printf("locked %s\n", argv[2]);
	sleep(30);
	pritnf("unlocked %s\n", argv[2]);
	exit(0);
}
