#include <stdio.h>
#include <stdlib.h> /*getenv, putenv 함수를 정의하는 헤더 파일*/

int main()
{
	char *home_dir;

	/*HOME 환경 변수값을 얻어와 출력*/
	if((home_dir=getenv("HOME"))!=NULL)
		printf("home directory : %s\n", home_dir);

	/*HOME 환경 변수값을 /home/jkim/book/linux로 설정*/
	putenv("Home=home/jkim/book/linux");

	if((home_dir=getenv("HOME"))!=NULL)
		printf("home directory : %s\n", home_dir);
}
