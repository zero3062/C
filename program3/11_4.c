#include <stdio.h>
#define MAX 100

int main()
{
	int i =123;
	float j=23.456;
	char buffer1[MAX], buffer2[MAX];

	sprintf(buffer1, "%d", i);
	sprintf(buffer2, "%.3f", j);

	sscanf(buffer1, "%o", &i);
	printf("%d\n", i);

	sscanf(buffer2, "%e", &j);
	printf("%e\n", j);
}
