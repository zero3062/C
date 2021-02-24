#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("one\n");
	if(fork()==-1)
		perror("fork failed");
	else
		printf("two\n");
}
