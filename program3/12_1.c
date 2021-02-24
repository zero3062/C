#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	printf("%d : %d\n", -345, abs(-345));
	printf("%d : %ld\n", -123456789, labs(-123456789));
	printf("%g : %g\n", -23.456, fabs(-23.456));
}
