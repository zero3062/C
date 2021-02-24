#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

main(int argc, char *argv[])
{
	int fd;
	struct flock filelock;

	/*쓰기 잠금*/
	filelock.l_type = F_WRLCK;
	/*파일 전체*/
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 0;

	fd = open(argv[1], O_RDWR);

	/*fd 파일에 대해 쓰기 잠금을 설정*/
	if(fcntl(fd, F_SETLK, &filelock) == -1) {
		/*레코드 잠금 정보를 filelock에 얻어옴*/
		fcntl(fd, F_GETLK, &filelock);
		/*filelock.l_pid는 잠금을 설정하고 있는 프로세스의 프로세스 ID*/
		fprintf(stderr, "%s locked by %d\n", argv[1], filelock.l_pid);
		exit(1);
	}
	exit(0);
}
