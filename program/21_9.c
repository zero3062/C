#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 100	/* buf의 크기를 나타내느 매크로 */

main()
{
	int fd, i;
	char buf[MAX];
	long int length = 0;

	if((fd==open("jkim", O_RDONLY))==-1) {
		perror("open failed");
		exit(1);
	}
	/* fd 파일의 크기를 계산하는 부분으로, read가 반환하는 값은
	   실제 읽어들인 데이터의 바이트 수다. */
	while((i=read(fd, buf, MAX)) > 0)
		length += i;
	printf("Total characters in jkim : %ld\n", length);
	close(fd);
	exit(0);
}
