#include <stdio.h>

int main()
{
	enum months {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC } mon;
	mon = JUL;
	printf("%d\n", mon);
	printf("%d\n", NOV);
}
