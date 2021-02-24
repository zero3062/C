#include <stdio.h>
int func1(); /*func1 함수 선언*/
int func2(); /*func2 함수 선언*/
int main()
{
	func1(); /*func1 함수 호출*/
	func2(); /*fucn2 함수 호출*/
}
/*func1함수 정의*/
int func1()
{
	printf("function 1\n");
	return 0;
}
/*func2 함수 정의*/
int func2()
{
	printf("function 2\n");
	return 0;
}
