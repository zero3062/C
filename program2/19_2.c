#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int fd;
	/*nodata파일을 읽기 전용으로 연다*/
	if((fd=open("nodata", O_RDONLY))==-1) { /*open함수 호출에 실패하면 -1 반환*/
		printf("errno = %d\n", errno); /*오류가 발생하면 errno에 오류 번호 저장*/
		exit(1);
	}
	exit(0);
}
