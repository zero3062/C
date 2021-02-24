#include <stdio.h>
#include <stdlib.h> /* getenv, setenv 함수를 정의하는 헤더파일*/
#include <string.h> /* strcpy, strcat 함수를 정의하는 헤더 파일*/

int main(int argc, char *argv[])
{
	char *value, *string;

	if(argc==1 || argc>3) {
		printf("Usage : a.out variable[value]\n");
		exit(1);
	}

	/*argv[1] 환경 변수갑을 얻어와 출력 */
	if((value=getenv(argv[1]))!= NULL)
		printf("%s : %s\n", argv[1], value);
	else
		printf("%s : no value\n", argv[1]);

	/*명령라인 인수가 세 개면 */
	if(argc==3) {
		/*메모리를 동적으로 할당받음*/
		string =(char*)malloc(strlen(argv[1]) + strlen(argv[2]) +2);
		/*argv[1]을 string에 복사*/
		strcpy(string, argv[1]);
		/*string 뒤에 '='을 연결*/
		strcat(string, "=");
		strcat(string, argv[2]);

		/*환경 변수값을 변경 */
		putenv(string);

		/*변경된 환경 변수값을 얻어와 출력*/
		if((value=getenv(argv[1])) != NULL)
			printf("%s's new value : %s\n", argv[1], value);
		else
			printf("error : %s\n", string);
	}
	exit(0);
}


