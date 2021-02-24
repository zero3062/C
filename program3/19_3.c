#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

int main()
{
	double y;

	errno = 0;
	y = sqrt(-1);

	if(errno != 0) {
		printf("errno = %d\n", errno);
		exit(1);
	}
	exit(0);
}
