#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct stat st1, st2;

	/*argv[1]에 심볼릭 링크 argv[2]를 생성*/
	if(symlink(argv[1], argv[2]) == -1) {
		perror("stmlink failed");
		exit(1);
	}
	/*stat를 이용하여 심볼릭 링크 argv[2]에 대한 정보를 st1에 저장.
	  심볼릭 링크가 가리키는 파일에 대한 정보가 저장 */
	if(stat(argv[2], &st1)==-1) {
		perror("stat failed");
		exit(1);
	}
	/*lstat를 이용하여 심볼릭 링크 argv[2]에 대한 정보를 st2에 저장.
	  심볼릭 링크 자체에 대한 정보가 저장 */
	if(lstat(argv[2], &st2) == -1){
		perror("stat failed");
		exit(1);
	}
	printf("%ld bytes : %ld bytes\n", st1.st_size, st2.st_size);
	exit(0);
}
