#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAXARG 7

int main()
{
	char buf[256];
	char *arg[MAXARG];
	char *s;
	char *save;
	int argv;
	static const char delim[] = " \t\n";
	int pid, status;

	while(1) {
		printf("myshell: ");
		fgets(buf, 256, stdin);
		argv=0;
		s=strtok_r(buf, delim, &save);
		while(s) {
			arg[argv++]=s;
			s=strtok_r(NULL, delim, &save);
		}
		arg[argv] = (char *)0;

		if(!strcmp(arg[0], "quit"))
			break;

		if((pid=fork())==-1)	
			perror("fork failed");
		else if(pid!=0) {
			pid=wait(&status);
		} else {
			execvp(arg[0], arg);
		}
	}
	exit(0);
}
