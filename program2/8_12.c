#include <stdio.h>
#include <string.h> /* strstr 함수가 정의된 헤더 파일 */

int main()
{
	char *str = "Hello Linux Programming, Linuxer";
	char *ptr;

	/* 문자열 str에서 문자열 "Linux"가 처음으로 발견되는 위치를 검색하고 포인터를 반환 */
	ptr = strstr(str, "Linux");
	printf("%s\n", ptr);
}
