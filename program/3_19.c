#include <stdio.h>
main()
{
	int ch;

	/* ch가 'A'보다 크거나 같으면 반복 실행 */
	for(ch='Z'; ch>= 'A'; ch--)
		printf("%c", ch);
	printf("\n");
}
