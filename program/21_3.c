#include <fcntl.h>

main()
{
	int fd;

	/* jkim 파일을 읽기 전용으로 열기.
	   만약 호출에 실패하게 되면 -1이 반환되므로 if 조건이 참이 됨 */
	if((fd==open("jkim", O_RDONLY))==-1) {
		perror("open failed");
		exit(1);
	}
	/* fd 파일 닫기 */
	close(fd);
	exit(0);
}
