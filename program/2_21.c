#include <stdio.h>
func(); /* func라는 함수가 있다는 내용을 컴파일러에 알려주기 위해 함수 선언 */
main()
{
	printf("before function call\n");
	func(); /* func 함수의 선언과 정의가 되어 있으므로 함수 호출에 성공한다. */
	printf("after function call\n");
}
func() /* 함수 정의 */
{
	printf("running function\n");
}
