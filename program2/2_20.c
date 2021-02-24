#include <stdio.h>
int func();

int main()
{
	printf("before function call\n");
	func();	/* 함수 호출 */
	printf("after function call\n");
}
/* 함수 정의 */
int func()
{
	printf("running function\n");
}
