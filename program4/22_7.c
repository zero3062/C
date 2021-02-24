#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	/*dir 디렉토리를 0755 권한으로 생성*/
	if(mkdir("dir", 0755) == -1) {
		perror("mkdir failed");
		exit(1);
	}
	/*dir 디렉토리 삭제*/
	if(rmdir("dir") == -1) {
		perror("rmdir faiiled");
		exit(2);
	}
	exit(0);
}
