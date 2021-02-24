#include <stdio.h>

int main()
{
	float arr[3];
	int i;

	for(i=0;i<3;i++)
		printf("arr[%d]: %p ", i, &arr[i]);
	printf("\n");
}
