#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	if((pid=fork())==-1)
		perror("fork failed");
	else if(pid!=0)
		printf("PID is %d, child process pid is %d\n", getpid(), pid);
	else 
		printf("PID is %d, parent process pid is %d\n", getpid(), getppid());
}
