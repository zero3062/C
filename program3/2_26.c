#include <stdio.h>

void func(void);

int main()
{
	printf("before function call\n");
	func();
	printf("after function call\n");
}

void func(void)
{
	printf("running function\n");
}
