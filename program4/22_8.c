#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h> /*strlen 함수가 정의된 헤더 파일*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;

	if(mkdir(argv[1], 0755) == -1) { /*argv[1] 디렉토리를 생성*/
		perror("mkdir faile");
		exit(1);
	}

	if(mkdir(argv[1], 0755) == -1) { /*argv[1]디렉토리로 이동*/
		perror("chdir failed");
		exit(1);
	}

	/*argv[2] 파일을 쓰기 전용으로 여는데 만약 파일이 없으면 생성*/
	if((fd=open(argv[2], O_WRONLY|O_CREAT, 0644)) == -1) {
		perror("open failed");
		exit(1);
	}

	write(fd, argv[3], strlen(argv[3])); /*fd파일에 argv[3] 문자열 쓰기*/

	close(fd);
	exit(0);
}
