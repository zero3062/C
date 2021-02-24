#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	if((pid=fork()) == -1){
		perror("fork failed");
		exit(1); /*fork호출에 실패하면 1을 반환하고 종료*/
	}else if(pid!=0) {
		printf("parent process\n");
		exit(2); /*부모 프로세스는 2를 반환하고 종료*/
	}else {
		printf("chile process\n");
		exit(3); /*자식 프로세스는 3을 반환하고 종료*/
	}
}
