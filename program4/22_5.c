#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct stat st;

	if(stat(argv[1], &st) == -1) {
		perror("stat failed");
		exit(1);
	}

	if(S_ISREG(st.st_mode)) { /*정규 파일이면*/
		printf("regular\n");
	} else if(S_ISDIR(st.st_mode)) { /*디렉토리면 */
		printf("directory\n");
	} else if(S_ISCHR(st.st_mode)) { /*문자 특수 파일이면*/
		printf("charavter sqecial\n");
	} else if(S_ISBLK(st.st_mode)) { /*블록 특수 파일이면 */
		printf("block sqecial\n");
	} else if(S_ISFIFO(st.st_mode)) { /*FIFO 파일이야*/
		printf("fifl\n");
	}
	exit(0);
}
