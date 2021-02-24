#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int pid, status;

	if((pid=fork())==-1)
		perror("fork failed");
	else if(pid!=0) {
		while(waitpid(pid, &status, 0)==0) {
			printf("still waiting\n");
			sleep(1);
		}
	} else {
		printf("run child\n");
		sleep(5);
		exit(0);
	}
}
