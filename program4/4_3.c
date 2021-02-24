#include <stdio.h>

int main()
{
	float arr[3];
	int i;

	for(i=0; i<3; i++)
		/*arr[i]의 주소 출력 주소는 음수가 없으므로 %u형태로 출력*/
		printf("arr[%d]: %f", i, arr[i]);
	printf("\n");
}
