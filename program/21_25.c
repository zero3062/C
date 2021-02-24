#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int filestatus(int fd, char *file);

main(int argc, char *argv[])
{
	int fd, newfd, mode;

	/* argv[2]에 저장되어 있는 정수 형태의 문자열을 정수로 변환하여 mode에 저장 */
	mode = atoi(argv[2]);
	if((fd=open(argv[1], mode))==-1) {
		perror("open failed");
		exit(1);
	}
	if(filestatus(fd, argv[1]) == -1) {
		exit(2);
	}
	close(fd);
	exit(0);
}

int filestatus(int fd, char *file)
{
	int flag;

	/* 파일의 상태 정보를 알아내 flag에 저장. 가장 우측 두 개의 비트는 00, 01, 또는 */
	if((flag=fcntl(fd, F_GETFL)) == -1) {
		perror("fcntl failed");
		return -1;
	}
	/* O_ACCMODE는 3이므로 flag & O_ACCMODE 결과는 flag의 가장 우측
	   두 개의 비트가 00이면 0, 01이면 1, 10이면 2기 된다. */
	switch (flag & O_ACCMODE) {
		case O_RDONLY:	/* O_RDONLY는 0으로 정의 */
			printf("%s is read only file\n", file);
			break;
		case O_WRONLY:	/* O_WRONLY는 1로 정의 */
			printf("%s is write only file\n", file);
			break;
		case O_RDWR:	/* O_RDWR는 2로 정의 */
			printf("%s is read-write file\n", file);
			break;
		default:
			printf("no such mode\n");
	}
	return 0;
}
