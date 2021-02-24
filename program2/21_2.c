#include <fcntl.h>
#include <unistd.h>
#define BUFFSIZE 1024

int main()
{
	int fd1, fd2;
	ssize_t n;
	char buf[BUFFSIZE];

	/* jkim 파일을 읽기 전용으로 열기. fd1은 jkim을 의미 */
	fd1 = open("jkim", O_RDONLY);
	/* kang 파일을 쓰기 전용으로 열기. fd2는 kang을 의미 */
	fd2 = open("kang", O_WRONLY);
	/* fd1 파일에서 문자를 BUFFSIZE 크기만큼 읽어 buf에 저장.
	   read 함수에서도 파일 식별자를 사용하고 반환값은 실제로 읽은 바이트 수 */
	n = read(fd1, buf, BUFFSIZE);
	/* buf에 있는 내용을 n바이트만큼 fd2 파일에 저장.
	   write 함수에서도 파일 식별자를 사용 */
	write(fd2, buf, n);
	/* fd1 파일 닫기 */
	close(fd1);
	close(fd2);
}
