#include <stdio.h>
int main()
{
	int i, j;

	/* j 값에 3을 대입하고 j에 4를 더한 값인 7을 i에 대입 */
	i = (j=3, j+4);
	printf("%d %d\n", i, j);
}
