#include <stdio.h>
main()
{
	printf("before function call\n");
	func();	/* 함수 호출 */
	printf("after function call\n");
}
/* 함수 정의 */
func()
{
	printf("running function\n");
}
