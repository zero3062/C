#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

main()
{
	int fd;
	/* nodata 파일을 읽기 전용으로 연다. */
	if ((fd=open("nodata", O_RDONLY)) == -1) {	/* open 함수 호출에 실패하면 -1 반환 */
		printf("errno = %d\n", errno);	 /* 오류가 발생하면 errno에 오류 번호 저장 */
		exit(1);
	}
	exit(0);
}
