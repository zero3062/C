#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *envp[] = {"USER=jkim", "PATH=/tmp", (char *)0};

int main()
{
	printf("Running ls with execle\n");
	execle("/bin/ls", "ls", (char *)0, envp);
	printf("execle failed to run ls\n");
	exit(0);
}
