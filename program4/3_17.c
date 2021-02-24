#include <stdio.h>
int main()
{
	int i;

	printf("Input integer == ");
	scanf("%d", &i);

	switch(i) {
		case 1:
			printf("Hello 1\n"); /*i가 1이면 이 문장만 실행*/
			break;
		case 2:
			printf("Hello 2\n");
			break;
		case 3:
			printf("Hello 3\n");
			break;
		default:
			printf("Hello others\n"); /*그 박의 경우에는 이 문장만 실행*/
	}
}
