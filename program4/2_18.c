#include <stdio.h>
int main()
{
	/*const를 사용해 값을 변경할 수 없는 변수 i를 선언한다*/
	const int i=10;
	i=20; /* 값을 변경할 수 없는 변수 i의 값을 변경하려고 함*/
	printf("%d\n", i);
}
	
