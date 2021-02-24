#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int fd;

	/*open 함수 호출에 실패하면 -1이 변환*/
	if((fd=open("nodata", O_RDONLY))==-1) {
		/*ENOENT는 '그와 같은 파일 또는 디렉토리가 없다'는 의미의 매크로*/
		if(errno==ENOENT)
			printf("nodata is noe exist\n");
		else
			printf("unexpected error: errno = %d\n", errno);
		exit(1);
	}
	exit(0);
}
