#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("%g\n", atof("1.23"));
	printf("%g\n", atof("0.12E12"));
	printf("%g\n", atof("\t-367.177abc"));
}
