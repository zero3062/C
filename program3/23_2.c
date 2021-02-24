#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	if((pid=fork()) ==-1)
		perror("fork failed");
	else if(pid!=0)
		printf("parent process\n");
	else
		printf("child process\n");
}
