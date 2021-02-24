#include <stdio.h>
int main()
{
	char ch = 'a';
	int i = 256;
	/*char형과 int형은 기본적으로 연산을 할 수 없으므로 크기가 더 작은 데이터형인
	  char형을 int형으로 자동 변환하여 연산한다*/
	printf("%d\n", ch+i);
}
