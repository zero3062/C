#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 1024

int main()
{
	int count;
	char buf[MAX];

	/* STDIN_FILENO는 표준 입력을 의미. 표준 입력은 키보드를 통해 이루어짐 */
	while((count=read(STDIN_FILENO, buf, MAX)) > 0) {
		/* STDOUT_FILENO는 표준 출력을 의미. 표준 출력은 모니터를 통해 이루어짐 */
		if(write(STDOUT_FILENO, buf, count) != count) {
			perror("write failed");
			exit(1);
		}
	}
	exit(0);
}
