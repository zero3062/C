#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#define MAX 512

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	char *dir;
	char filename[MAX];
	char list[MAX];
	char buf[MAX];
	struct stat st;
	int index;
	int i;

	/*명령라인 인수가 한 개라면 현재 작업 디렉토리에 대해 동작*/
	if(argc == 1)
		dir = ".";
	/*그렇지 않으면 argv[1] 디렉토리에 대해 동작 */
	else
		dir = argv[1];
	if((dp=opendir(dir)) == NULL) { /*dir디렉토리 열기*/
		perror("opendir failed");
		exit(1);
	}

	while ((dirp=readdir(dp))) { /*dp디렉토리의 모든 항복들에 대해 처리*/
		index = 0;
		if(!strncmp(dirp->d_name, ".", 1)) /*filename에 대해 정보를 st에 저장*/
			continue;
		sprintf(filename, "%s\%s", dir, dirp->d_name);
		if(lstat(filename, &st) == -1) { /*filename에 대한 정보를  st에 저장*/
			perror("stat failed");
			exit(1);
		}
		/*파일 형식을 알아내서 정규 파일은 '-'를, 디렉트리는 'd'를,
		  FIFO 파일은 'p'를, 그리고 링크는 '1'을 list[0]에 저장*/
		switch (st.st_mode & S_IFMT) {
			case S_IFREG:
				list[index++] = '-';
				break;
			case S_IFDIR : 
				list[index++] = 'd';
				break;
			case S_IFIFO : 
				list[index++] = 'p';
				break;
			case S_IFLNK:
				list[index++] = 'l';
		}
		/* 파일 접근 권한 알아내기*/
		for(i=0; i<3; i++){
			if(st.st_mode & (S_IREAD >> i*3))
				list[index++] = 'r';
			else 
				list[index++] = '-';
			if(st.st_mode & (S_IWRITE >> i*3))
				list[index++] = 'w';
			else 
				list[index++] = '-';
			if(st.st_mode & (S_IEXEC >> i*3))
				list[index++] = 'x';
			else
				list[index++] = '-';
		}
		list[index] = '\0'; /*문자열의 마지막을 의미*/
		/*링크 수, 파일 소유자*/
		printf("%s%5ld %s ", list, st.st_nlink, (getpwuid(st.st_uid))->pw_name);
		/*파일 그룹 이름, 파일 크기*/
		printf("%s%9ld ", (getgrgid(st.st_gid))->gr_name, st.st_size);
		/*파일 내용 최종 변경 시간 */
		sprintf(buf, "%s", ctime(&st.st_mtime));
		/*파일에 대한 최종 수정 시간을 ctime(&st.st_mtime)로 출력하면 개행이
		  자동으로 이러지므로 개행이 일어나지 않도록 '\n'위치에 '\0'을 넣음*/
		buf[strlen(buf) -1] = '\0';
		printf("%s %s\n", buf, dirp->d_name); /*파일 이름*/
	}
	closedir(dp);
	exit(0);
}
