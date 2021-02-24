#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	char *dir;

	/*명령 라인의 인수가 한 개라면 현재 작업 디렉토리에 대해 동작*/
	if(argc == 1)
		dir = ".";
	/*그렇지 않으면 argv[1] 디렉토리에 대해 동작*/
	else
		dir = argv[1];
	if((dp=opendir(dir))==NULL) { /*dir 디렉토리 열기*/
		perror("opendir failed");
		exit(1);
	}
	/*dp 디렉토리의 모든 항목들에 대한 이름을 출력
	  단, "."로 시작되는 항목에 대한 이름은 출력하지 않음*/
	while ((dirp=readdir(dp))){
		if(strcmp(dirp->d_name, ".", 1))
			printf("%s ", dirp->d_name);
	}
	printf("\n");
	closedir(dp); /*dp 디렉토리 닫기*/
	exit(0);
}
