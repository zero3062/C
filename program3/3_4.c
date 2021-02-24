#include <stdio.h>

int main()
{
	int i, fac, n;

	i = fac = 1;

	printf("Input number ==> ");
	scanf("%d", &n);
	while(i<=n) {
		fac *= i++;
	}
	printf("%d facorial : %d\n", n, fac);
}
