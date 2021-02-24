#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	if((pid=fork())==-1)
		perror("fork failed");
	/* 부모 프로세스는 자신과 자식 프로세스의 프로세스 ID 출력 */
	else if(pid!=0)
		/* getpid는 자신의 프로세스 ID를 반환하는 함수 */
		printf("PID is %d, child process pid is %d\n", getpid(), pid);
	/*자식 프로세스는 자신과 부모 프로세스의 프로세스 ID출력*/
	else 
		/*getppid는 부모 프로세스의 프로세스 ID를 반환하는 함수*/
		printf("PID is %d, parent process pid is %d\n", getpid(), getppid());
}
