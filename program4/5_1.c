#include <stdio.h>

void swap_val(int x, int y);
void swap_addr(int *x, int *y);

int main()
{
	int a=7, b=11;

	/*값에 의한 전달*/
	swap_val(a, b);
	printf("%d %d\n", a, b);

	/*주소에 의한 전달*/
	swap_addr(&a, &b);
	printf("%d %d\n", a, b);
}

void swap_val(int x, int y)
{
	int temp;

	/*x와 y의 값을 교환*/
	temp = x;
	x = y;
	y = temp;
}

void swqp_addr(int *x, int *y)
{
	int temp;

	/*x가 가리키는 값과 y가 가리키는 값을 교환*/
	temp = *x;
	*x =*y;
	*y = temp;
}
