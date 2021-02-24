#include <stdio.h>
int main()
{
	int i;

	printf("Input integer ==> ");
	scanf("%d", &i);
	/* i 값과 일치하는 case부터 실행하고 일치하는 상수식이 없으면 default 문 실행 */
	switch (i) {
		case 1: /* i가 1이면 여기부터 실행 */
			printf("Hello 1\n");
		case 2: /* i가 2이면 여기부터 실행 */
			printf("Hello 2\n");
		case 3: /* i가 3이면 여기부터 실행 */
			printf("Hello 3\n");
		default: /* 그 밖의 경우에는 여기부터 실행 */
			printf("Hello others\n");
	}
}
