#include <stdio.h>
#include <string.h> /* strcpy를 정의하고 있는 헤더 파일 */
main()
{
	char str[4];
	/* 문자열 상수르 배열 변수에 저장하기 위해 strcpy를 이용 */
	strcpy(str, "abc");
	printf("%s\n", str);
}
