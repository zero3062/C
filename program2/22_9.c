#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 100

int main(int argc, char *argv[])
{
	char name[MAX];

	/* 현재 작업 디렉토리 이름을 알아내서 출력 */
	getcwd(name, MAX);
	printf("directory name : %s\n", name);

	/* argv[1] 디렉토리를 생성하고 이동 */
	mkdir(argv[1], 0755);
	chdir(argv[1]);
	getcwd(name, MAX);
	printf("directory name : %s\n", name);

	/* 상위 디렉토리로 이동 */
	chdir("..");
	getcwd(name, MAX);
	printf("directory name : %s\n", name);

	/* argv[1] 디렉토리 삭제 */
	rmdir(argv[1]);

	exit(0);
}
