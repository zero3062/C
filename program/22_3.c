#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

main(int argc, char *argv[])
{
	int i;
	struct stat st;

	for(i=1; i<argc; i++) {
		if(stat(argv[i], &st) == -1) {
			perror("stat failed");
			exit(1);
		}
		/* 파일 형식과 접근 권한 등의 정보를 저장하고 있는 st.st_mode를
		   16진수 형태로 출력하는, 4자리 중 첫 번째 수는 파일 형식을 나타냄 */
		printf("%s's mode : %x\n", argv[2], st.st_mode);
	}

	exit(0);
}
