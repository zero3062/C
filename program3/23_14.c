#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Running ls with execl\n");
	execl("/bin/ls", "ls", (char *)0);
	printf("execl failed to  run ls\n");
	exit(0);
}
