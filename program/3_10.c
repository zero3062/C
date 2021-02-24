#include <stdio.h>
main()
{
	int i;
	short j;
	long k;
	unsigned l;

	/* sizeof는 데이터형 또는 변수의 크기를 알아내는 연산자 */
	printf("int: %d %d\n", sizeof(int), sizeof(i));
	printf("short: %d %d\n", sizeof(short), sizeof(j));
	printf("long: %d %d\n", sizeof(long), sizeof(k));
	printf("unsigned: %d %d\n", sizeof(unsigned), sizeof(l));
}
