#include <stdio.h>
void func(void);
main()
{
	printf("before function call\n");
	func();
	printf("after function call\n");
}
/* 반환값과 매개변수가 없음을 void로 명시하고 함수 정의 */
void func(void)
{
	printf("running function\n");
}
