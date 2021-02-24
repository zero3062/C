#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;

	/*"23"과 "567"은 정수가 아닌 문자열이므로 + 연산 불가*/
	i=atoi("23")+atoi("567");
	printf("%d\n",i);
}
