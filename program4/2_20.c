#include <stdio.h>
int main()
{
	printf("before function call\n");
	int func();
	printf("after function call\n");
}
/*함수 정의*/
int func()
{
	printf("running function\n");
	return 0;
}
