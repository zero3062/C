#include <stdio.h>
int main()
{
	/*변수 선언과 동시에 초기화*/
	int i = 10000; /*int i;와 i=10000; 가 한 문장으로*/
	long int j = 100000;
	unsigned int k = 50000;
	printf("i: %d\n", i);
	printf("j: %ld\n", j); /*%ld는 long을 10진 정수로 출력*/
	printf("k :%d\n", k); /*%u는 unsigned형을 10진 정수로 출력*/
}
