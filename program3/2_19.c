#include <stdio.h>

void func()
{
	printf("running function");
}

int main()
{
	printf("before function call\n");
	func();
	printf("after function call\n");
}
