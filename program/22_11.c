#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

main()
{
	DIR *dp;	/* 디렉토리 정보에 대한 포인터 */
	struct dirent *dirp;	/* 디렉토리의 한 항목의 정보에 대한 포인터 */

	if((dp=opendir(".")) == NULL) {	/* 현재(.) 디렉토리 열기 */
		perror("opendir failed");
		exit(1);
	}
	/* dp 디렉토리의 항목들을 하나씩 읽어 항목 이름ㅇ르 출력한다.
	   더 이상 읽을 항목이 없으면 NULL이 반환된다. */
	while(dirp=readdir(dp)) {
		printf("%s ", dirp->d_name);
	}
	printf("\n");
	closedir(dp);	/* dp 디렉토리 닫기 */
	exit(0);
}
