#include <stdio.h>
#include <string.h> /*strchr 함수가 정의된 헤더 파일*/

int main()
{
	char *str="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ptr;

	/*문자열 str에서 문자 'K'가 첫 번째로 나오는 위치를 검색하고 포인터를 반환*/
	ptr = strchr(str, 'K');
	printf("%s\n", ptr);
}
