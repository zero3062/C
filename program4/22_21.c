#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*jkim의 접근 권한을 0644로 변경
	  소유자는 읽기, 쓰기 권한 , 그룹과 기타 사용자들은 읽기 권한이 부여*/
	if(chmod("jkim", 0644) == -1)
		perror("chmod failed");
	/*kang의 접근 권한을 변경
	  소유자는 읽기, 쓰기 권하느 긃과 기타 사용자들은 읽기 권한이 부여*/
	if(chmod("kang", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
		perror("chmod failed");
	exit(0);
}
