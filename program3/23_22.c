#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *envp[] = {"USER=jkim", "PATH=/tmp", (char *)0};

int main()
{
	char *arg[] = {"23_21", (char *)0};	
	printf("Running %s with execve\n", arg[0]);
	execve("./23_21", arg, envp);
	printf("execve failed to run %s\n", arg[0]);
	exit(0);
}
