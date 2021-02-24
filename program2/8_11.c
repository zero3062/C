#include <stdio.h>
#include <string.h> /* strrchr 함수가 정의된 헤더 파일 */

int main()
{
	char *str = "ABCABCABCABCABC";
	char *ptr;

	/* 문자열 str에서 문자 'A'가 마지막으로 발견되는 위치를 검색하고 포인터를 반환 */
	ptr = strrchr(str, 'A');
	printf("%s\n", ptr);
}
