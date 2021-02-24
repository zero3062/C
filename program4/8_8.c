#include <stdio.h>
#include <string.h> /*strdup함수가 정의된 헤더 파일*/

int main()
{
	/*문자열 포인터 변수*/
	char *ptrstr;

	/*strdup는 문자열 포인터 변수에서 사용할 수 있지만 문자열 배열 변수에서는
	  사용할 수 없음
	  메모리를 할당해 "Hello Linux"를 저장하고 이 문자열을 ptrstr이 가리키게됨*/
	ptrstr = strdup("Hello Linux");
	printf("%s\n", ptrstr);
}
