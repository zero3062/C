#include <stdio.h>
#include <string.h> /* memchr, strlen함수가 정의된 헤더 파일*/

int main()
{
	char *string = "ABCDEABCDEABCDE";

	while(1) {
		/*string이 가리키는 영역의 strlen(string) 바이트에서 첫 번재 'A'를 
		  검색하여 발견하면 이에 대한 포인터를 바환하여 string이 이를 가리키고
		  만약 발견하지 못하면 NULL을 반환*/
		if((string=memchr(string, 'A', strlen(string))) == NULL)
			break; /*발견하지 못하면 while문을 벗어남*/
		printf("%s\n", string);
		/*string이 다음 문자를 가리키도록 함*/
		string++;
	}
}
