#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define SIZE 20

int main(int argc, char *argv[])
{
	int fd;
	struct flock filelock;
	char buffer[SIZE];
	int length;

	filelock.l_type = F_RDLCK; /*읽기 잠금*/
	/*파일 전체를 영역으로*/
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 0;

	fd=open(argv[1], O_RDONLY); /*argv[1] 파일 열기*/

	/*fd파일에 대해 읽기 잠금을 설정
	  이미 레코드 잠금이 설정되어 있으면 해제될 때까지 기다림*/
	if(fcntl(fd, F_SETLKW, &filelock)==-1){
		perror("fcntl failed");
		exit(1);
	}
	printf("locked %s\n", argv[1]);
	/*파일에서 데이터 일기*/
	length=read(fd, buffer, SIZE);
	/*읽은 데이터를 표준 출력 장치에 출력*/
	write(STDOUT_FILENO, buffer, length);
	printf("unlocked %s\n", argv[1]);
	exit(0);
}
