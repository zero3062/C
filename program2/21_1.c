#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd1, fd2;

	/* jkim 파일을 읽기 전용으로 열기. 반환되는 양의 정수값을 파일 식별자라 함 */
	fd1 = open("jkim", O_RDONLY);
	/* kang 파일을 쓰기 전용으로 열기 */
	fd2 = open("kang", O_WRONLY);
	/* 배정받은 파일 식별자를 출력 */
	printf("jkim's file descriptor: %d\nkang's file descriptor: %d\n", fd1, fd2);
	/* 파일 식별자를 이용해서 파일 닫음 */
	close(fd1);
	close(fd2);
}
