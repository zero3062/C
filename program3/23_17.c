#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *arg[] = {"ls", (char *)0};
	printf("Running ls with execv\n");
	execv("/bin/ls", arg);
	printf("execv failed to run ls\n");
	exit(0);
}
