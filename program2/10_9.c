#include <stdio.h>
#include <string.h> /*memcmp함수가 정의된 헤더 파일*/

int main()
{
	char *quit = "quit";
	char *string;

	while(1) {
		printf("Input string ==> ");
		scanf("%c", string);
		/*string과 quit의 처음 4바이트를 비교해 같으면 0을 반환하므로 조건이 참이 됨*/
		if(!memcmp(string, quit, 4))
			break;
		printf("%s\n", string);
	}
}
