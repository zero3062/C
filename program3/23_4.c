#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;

	if((pid=vfork())==-1)
		perror("fork failed");
	else if(pid!=0)
		printf("PID is %d, child process pid is %d\n", getpid(), pid);
	else {
		printf("PID is %d, paarent process pid is %d\n", getpid(), getppid());
		exit(0);
	}
}
