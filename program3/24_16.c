#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 100

int main()
{
	char buffer[MAX];
	int n;

	alarm(10);
	n=read(0, buffer, MAX);
	alarm(0);
	write(1, buffer, n);
	exit(0);
}
