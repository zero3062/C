#include <stdio.h>
int main()
{
	int ch='Z';
	/* 07라인을 먼저 실행하고 조건식을 검사한다. */
	do {
		printf("%c", ch--);
	} while (ch >= 'A'); /* ch가 'A'보다 크거나 같으면 반복 실행 */
	printf("\n");
}
