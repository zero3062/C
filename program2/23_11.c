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
	/*부모 프로세스*/
	else if(pid!=0) {
		/*waitpid의 세번째 인수를 0으로 설정하면 부모 프로세스는 자식 프로세스가
		  종료될때까지 블록화됨. 자식 프로세스가 종료되면 잣기 프로세스의 프로세스
		  ID가 반환되므로 while 문을 벗어남 */
		while(waitpid(pid, &status, 0)==0) {
			printf("still waiting\n");
			sleep(1);	/*1초 동안 실행을 중단*/
		}
	/*자식 프로세스*/
	} else {
		printf("run child\n");
		sleep(5);
		exit(0);
	}
}
