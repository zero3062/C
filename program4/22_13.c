#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	DIR *dp;
	struct dirent *dirp;

	if((dp=opendir(".")) == NULL) { /*현재 디렉토리 열기*/
		perror("opendir failed");
		exit(1);
	}
	/*디렉토리의 항목들을 읽어서 이름을 출력 */
	while ((dirp=readdir(dp))) {
		printf("%s", dirp->d_name);
	}
	printf("\n");

	rewinddir(dp); /*디렉토리 포인터를 첫 번째 항목으로 되돌림*/
	while ((dirp=readdir(dp))) {
		printf("%s", dirp->d_name);
	}
	printf("\n");

	closedir(dp); /*dp디렉토리 닫기*/
	exit(0);
}
