#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

main(int argc, char *argv[])
{
	int fd;

	if((fd=creat(argv[1], 0644))==-1) {
		perror("open failed");
		exit(1);
	}
	write(fd, "abcdefghijklmnopqrstuvwxyz", 26);
	/* 파일의 끝보다 더 뒤의 위치를 지정하는 것도 가능하며
	   빈 공간은 NULL로 채워짐 */
	 if(lseek(fd, 30, SEEK_SET) == -1) {
		 perror("lseek failed");
		 exit(1);
	 }
	 write(fd, "ABCD", 4);
	 close(fd);
	 exit(0);
}
