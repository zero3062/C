#include <stdio.h>
#include <ctype.h>	/* isalpha 함수가 정의된 헤더 파일 */

int main()
{
	int ch;

	while((ch=getchar()) != EOF) {
		/* ch가 영문자면 참이 되고 아니면 거짓 */
		if(isalpha(ch))
			putchar(ch);
	}
	putchar('\n');
}
