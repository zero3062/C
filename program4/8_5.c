#include <stdio.h>
#include <string.h> /*strcat, strncat함수가 정의된 헤더 파일*/

int main()
{
	char buf1[20] ="Linux";
	char buf2[20] ="Linux";

	strcat(buf1, "Programming"); /* "Programming"을 buf1에 연결*/
	strncat(buf2, "Programming", 5); /*"Programming"중 5개의 문자를 buf2에 연결*/

		printf("%s\n%s\n", buf1, buf2);
}
