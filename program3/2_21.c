#include <stdio.h>

void func();

int main()
{
	printf("before function call\n");
	func();
	printf("after function call\n");
}

void func()
{
	printf("running function\n");
}
