#include <stdio.h>

void func1();
void func2();

int main()
{
	func1();
	func2();
}

void func1()
{
	printf("function 1\n");
}

void func2()
{
	printf("function 2\n");
}
