#include <stdio.h>

int sum(int n);

int main()
{
	int n;
	printf("Input number => ");
	scanf("%d", &n);
	printf("sum of 1-%d : %d\n", n, sum(n));
}

int sum(int n)
{
	if(n==1)
		/*재귀호출을 종료하는 조건을 나타낸 것으로 n이 1이면 1을 반환*/
		return 1;
	else
		/*자기 자신인  sum(n-1)을 호출하므로 재귀호출*/
		return n+sum(n-1);
}
