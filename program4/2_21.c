#include <stdio.h>
int func(); /*func라는 함수가 잇다는 내용을 컴파일러에 알려주기 위한 함수 선언*/
int main()
{
	printf("before function call\n");
	func(); /*func함수의 선언과 정의가 되어 있으므로 함수 호출에 성공한다*/
	printf("after function call\n");
}
int func() /*함수 정의*/
{
	printf("running function\n");
	return 0;
}
