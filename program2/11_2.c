#include <stdio.h> /*gets, puts함수가 정의된 헤더 파일*/
#define MAX 128

int main()
{
	char str[MAX];

	/*표준 입력으로 한 행의 문자열을 입력받아 str에 저장*/
	while(fgets(str, MAX, stdin)!=NULL) {
		/*문자열 str을 표준 출력으로 출력하고 개행*/
		puts(str);
	}
}
