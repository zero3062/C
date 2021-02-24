#include <stdio.h>
int main()
{
	int ch;

	/* 키보드로부터 하나의 문자를 입력받아 ch에 저장 */
	while((ch=getchar()) != EOF) {
		/* ch에 저장된 내용이 '\n'이면 */
		if (ch == '\n') {
			break;	/* while문을 벗어남 */
		}
		putchar(ch); /* ch에 저장된 문자를 화면에 출력 */
	}
	putchar('\n');
}
