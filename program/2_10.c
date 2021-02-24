#include <stdio.h>
main()
{
	/* sizeof는 데이터형의 크기를 알아내는 연산자로 단위는 바이트 수 */
	printf("int: %d\n", sizeof(int));
	printf("short: %d\n", sizeof(short));
	printf("long: %d\n", sizeof(long));
	printf("unsigned: %d\n", sizeof(unsigned));
}

