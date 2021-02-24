#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 100

int main()
{
	char buffer[MAX];
	int n;

	alarm(10); /*10초 후에 SIGALRM 시그널을 자신에게 보냄*/
	n = read(0, buffer, MAX);
	/*SIGALAM 시그널을 받기 전에 실행하면 SIGALRM 시그널 요청은 취소*/
	alarm(0);
	write(1, buffer, n);
	exit(0);
}
