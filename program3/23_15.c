#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Running ls with execlp\n");
	execlp("ls", "ls", (char *)0);
	printf("execlp failed to run ls\n");
	exit(0);
}
