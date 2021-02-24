#include <stdio.h>
int plus(int x, int y);
int minus(int x, int y);
int main()
{
	/*plus와 minus는 직접 만든 라이브러리 내에 있는 함수*/
	printf("%d %d\n", plus(2, 3), minus(2, 3));
}
