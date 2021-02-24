#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct stat st;

	if(stat(argv[1], &st) == -1) { /*argv[i] 파일에 대한 정보가 st에 저장*/
		perror("stat failed");
		exit(1);
	}
	/*argv[2]의 소유자와 그룹을 st.st_uid와 st.st_gid로 변경*/
	if(chown(argv[2], st.st_uid, st.st_gid) == -1) {
		perror("chown failed");
		exit(1);
	}
	exit(0);
}
