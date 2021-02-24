#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

int main()
{
	DIR *dp; /*디렉토리 정보에 대한 포인터*/

	if(mkdir("dir", 0755) == -1){ /*dir 디렉토리를 생성*/
		perror("mkdir failed");
		exit(1);
	}

	/*dir 디렉토리를 여는데 디렉토리 정보에 대한 포인터가 반환*/
	if((dp=opendir("dir")) == NULL) {
		perror("opendir failed");
		exit(1);
	}
	closedir(dp); /*dp 디렉토리 닫기*/
	exit(0);
}
