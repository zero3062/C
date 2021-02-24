#include <stdio.h>
int main()
{
	int i=10;
	int *ptr; /*포인터 변수 ptr 선언*/

	ptr = &i; /*i의 주소를 ptr에 저장*/
	(*ptr)++; /*ptr이 가리키는 내용을 1 증가시킴*/
	printf("%d\n", i);
}
