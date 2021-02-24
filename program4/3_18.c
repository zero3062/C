#include <stdio.h>
int main()
{
	int ch = 'Z';

	/*조건(ch >= 'A')이 참이면 반복 실행하고 거짓이면 while문을 벗어난다*/
	while(ch>='A')
		printf("%c", ch--);
	printf("\n");
}
