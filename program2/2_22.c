#include <stdio.h>
int func1(); /* func1 함수 선언 */
int func2(); /* func2 함수 선언 */
int main()
{
	func1(); /* func1 함수 호출 */
	func2(); /* func2 함수 호출 */
}
/* func1 함수 정의 */
int func1()
{
	printf("function 1\n");
}
/* func2 함수 정의 */
int func2()
{
	printf("function 2\n");
}
