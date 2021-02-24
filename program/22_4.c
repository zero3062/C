#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

main(int argc, char *argv[])
{
	struct stat st;

	if(stat(argv[1], &st) == -1) {
		perror("stat failed");
		exit(1);
	}

	/* st.st_mode & S_IFMT은 파일 형식을 알아내는 수식 */
	switch(st.st_mode & S_IFMT) {
		case S_IFREG:	/* 정규 파일이면 */
			printf("regular\n");
			break;
		case S_IFDIR:	/* 디렉토리면 */
			printf("directory\n");
			break;
		case S_IFCHR:	/* 문자 특수 파일이면 */
			printf("character special\n");
			break;
		case S_IFBLK:	/* 블록 특수 파일이면 */
			printf("block special\n");
			break;
		case S_IFIFO:	/* FIFO 파일이면 */
			printf("fifo\n");
	}
	exit(0);
}
