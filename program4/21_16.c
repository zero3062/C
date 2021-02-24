#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{

	int fd=0, count;
	char buf[MAX];

	if((fd == open("alphabet", O_RDONLY)) == 0) {
		perror("open failed");
		exit(1);
	}
	/*fd파일의 읽기/쓰기 포인터를 첫 위치로부터 뒤로 5칸 이동 */
	lseek(fd, 5, SEEK_SET);
	count = read(fd, buf, MAX);
	/*표준 출력 장치로 buf에 있는 count 바이트의 데이터를 출력*/
	write(STDOUT_FILENO, buf, count);
	close(fd);
	exit(0);
}
