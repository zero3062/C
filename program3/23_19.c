#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *envp[] = {"USER=jkim", "PATH=/tmp", (char *)0};

int main()
{
	char *arg[] = {"ls", (char *)0};
	printf("Running ls with execv\n");
	execve("/bin/ls", arg, envp);
	printf("execve failed to run ls\n");
	exit(0);
}
