#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 100

int main(int argc, char *argv[])
{
	char name[MAX];

	getcwd(name, MAX);
	printf("directory name : %s\n", name);

	mkdir(argv[1], 0755);
	chdir(argv[1]);
	getcwd(name, MAX);
	printf("directory name : %s\n", name);

	chdir("..");
	getcwd(name, MAX);
	printf("directory name : %s\n", name);

	rmdir(argv[1]);

	exit(0);
}
