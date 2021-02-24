#include <stdio.h>

int fibo(int n);

int main()
{
	int n;
	printf("Input number => ");
	scanf("%d", &n);
	printf("%d'th fibonacci number : %d\n", n, fibo(n));
}

int fibo(int n)
{
	/*재귀호출을 종료하는 조건으로 n이 1이거나 2이면 1을 반환*/
	if(n==1 || n==2)
		return 1;
	else
		/*자기자신인 fibo를 호출하므로 재귀호출*/
		return fibo(n-1)+fibo(n-2);
}
