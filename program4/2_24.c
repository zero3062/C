#include <stdio.h>
/*함수 선언, func 함수가 있다는 내용뿐만 아니라 int형 값을 반환할 것이라는
  내용을 컴파일러에 알려준다. 여기에서 매개변수 이름인 n1과 n2를 생략해
  func(int, int);라고 선언해도 되나 매개변수 이름을 써주는 것이 알아보기 쉽다.*/
int func(int n1, int n2);
int main()
{
	func(11, 7); /*함수 호출 11과 7을 보냄*/
}
/*매개변수가 잇는 함수 정의 n1에 11을 n2에 7ㅇ,ㄹ 저장하고 동작한다*/
int func(int n1, int n2)
{
	printf("%d %d\n", n1, n2);
	return 0;
}
