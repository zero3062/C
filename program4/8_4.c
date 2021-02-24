#include <stdio.h>
#include <ctype.h> /*islower, toupper, isupper, tolower 함수에 정의된 헤더파일*/

int main()
{
	int ch;

	while((ch=getchar()) != EOF) {
		/*소문자면*/
		if(islower(ch))
			/*대문자 변환*/
			ch = toupper(ch);
		/*대문자면*/
		else if(isupper(ch))
			/*소문자로 변환*/
			ch = tolower(ch);
		putchar(ch);
	}
	putchar('\n');
}
