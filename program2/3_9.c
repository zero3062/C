#include <stdio.h>
int main()
{
	char ch;

	while ((ch=getchar()) != EOF)
		/* ch에 저장된 값이 대문자면 소문자로 바꾸어 출력하고
		   나머지 문자는 그대로 출력. 즉 조건이 참이면 ch-'A'+'a'가 선택되고
		   거짓이면 ch가 선택됨 */
		printf("%c", ((ch>='A')&&(ch<='Z')) ? ch-'A'+'a' : ch);
}
