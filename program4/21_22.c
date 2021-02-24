#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd;

	/*1번 파일 식별자에 새로운 파일 식별자를 부여받아 fd에 저장한다.
	  1번은 표준 출력을 의미하므로 fd도 표준 출력을 나타낸다. */
	if((fd=dup(1)) == -1) {
		perror("dup failed");
		exit(1);
	}
	/*fd번 파일에 "ABCD"를 쓰는 동작으로 표준 출력 장치인 모니터로 출력 */
	write(fd, "ABCD", 5);
	exit(0);
}

