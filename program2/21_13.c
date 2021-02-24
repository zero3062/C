#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 1024

int main(int argc, char *argv[])
{
	int fd1, fd2;
	int count;
	char buf[MAX];
	/* 명령 라인의 인수가 세 개가 아니면 오류 메시지를 출력하고 종료한다. */
	if(argc != 3) {
		perror("argc is not 3");
		exit(1);
	}
	/* argv[1] 파일을 읽기 전용으로 연다. 실행 예에서는 file1이 된다. */
	if((fd1=open(argv[1], O_RDONLY)) == -1) {
		perror("open failed");
		exit(1);
	}
	if((fd2=open(argv[2], O_WRONLY | O_CREAT, 0644))==-1) {
		perror("open failed");
		exit(1);
	}
	/* fd1 파일로부터 MAX 바이트만큼의 데이터를 읽어서 buf에 저장 */
	while((count=read(fd1, buf, MAX)) > 0) {
		/* fd2 파일에 buf에 있는 count바이트만큼의 데이터 쓰기 */
		if(write(fd2, buf, count) != count) {
			perror("write failed");
			exit(1);
		}
	}
	close(fd1);
	close(fd2);
	exit(0);
}
