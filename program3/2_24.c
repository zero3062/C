#include <stdio.h>

void func(int n1, int n2);

int main()
{
	func(11, 7);
}

void func(int n1, int n2) 
{
	printf("%d %d\n", n1, n2);
}
