#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;

	/*vfork를 이용해 자식 프로세스 생성*/
	if((pid=vfork()) == -1)
		perror("fork failed");
	/*부모 프로세스는 자식 프로세스가 exit호출을 한 후에 동작*/
	else if(pid!=0)
		printf("PID is %d, child process pdi is %d\n", getpid(), pid);
	/*자식 프로세스는 곧바로 실행*/
	else{
		printf("PID is %d, parent process pid is %d\n", getpid(), getppid());
		exit(0);
	}
}
