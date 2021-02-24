#include <stdio.h>
int main()
{
	/*c와 d를 2로 설정*/
	int a,b,c=d=2;
	/*선 증가의 경우*/
	a = ++c;
	/*후 증가의 경우*/
	b = d++;
	/*c가 증가된 다음 그 값이 a에 할당되며, d의 값이 먼저 b에 할당된다*/
	printf("a: %d b: %d cL %d d: %d\n", a,b,c,d);
}
