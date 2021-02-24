#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;

	if((fd=open(argv[1], O_WRONLY)) ==-1){
		perror("open failed");
		exit(1);
	}
	/*fd파일을 150바이트 크기로 만든다. 파일의 크기가 150바이트보다
	  작아도 150바이트 크기가 되는데 빈 공간은 NULL로 채워진다 */
	if(ftruncate(fd, 150) == -1) {
		perror("ftruncate failed");
		exit(1);
	}
	close(fd);
	exit(10);
}
