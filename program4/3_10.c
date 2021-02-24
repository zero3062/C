#include <stdio.h>
int main()
{
	int i;
	short j;
	long k;
	unsigned l;
	
	/*sizeof는 데이터형 또는 변수의 크기를 알아내는 연산자*/
	printf("int: %ld %ld\n", sizeof(int), sizeof(i));
	printf("short: %ld %ld\n", sizeof(short), sizeof(j));
	printf("long: %ld %ld\n", sizeof(long), sizeof(k));
	printf("unsigned: %ld %ld\n", sizeof(unsigned), sizeof(l));
}
