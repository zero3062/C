#include <stdio.h>

int main()
{
	int a, b, c=2, d=2;

	a= ++c;
	b = d++;

	printf("a:%d b:%d c:%d d:%d\n", a, b, c, d);
}
