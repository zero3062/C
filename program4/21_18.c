#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int agrc, char *argv[])
{
	int fd;
	off_t filesize;

	if((fd = open(argv[1], O_RDONLY)) ==-1) {
		perror("open failed");
		exit(1);
	}
	/*읽기/쓰기 포인터가 파일의 끝을 가리키게 되고.
	  변경된 읽기/쓰기 포인터가 반환되는데, 이는 파일의 크기가 된다 */
	if((filesize=lseek(fd, 0, SEEK_END)) == -1) {
		perror("lseek failed");
		exit(1);
	}
	printf("%s\'s size is %ld\n", argv[1], filesize);
	close(fd);
	exit(0);
}
