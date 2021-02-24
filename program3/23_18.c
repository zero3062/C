#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *arg[] = {"ls", (char *)0};
	printf("Running ls with execvp\n");
	execvp("ls", arg);
	printf("execvp failed to run ls\n");
	exit(0);
}
