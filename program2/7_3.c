#include <stdio.h>
#define SIZE 1000	/* 매크로 SIZE 정의 */

int main()
{
	int num;
	num = SIZE;
	printf("%d\n", num);

#undef SIZE	/* 매크로 SIZE 해제 */
#define SIZE 5000	/* 매크로 SIZE 정의 */

	num = SIZE;
	printf("%d\n", num);
}
