#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*환경 변수 정보 설정*/
char *envp[] = {"USER = jkim", "PATH=/tmp", (char *)0};

int main()
{
	char *arg[] = {"23-_21", (char *)0}; /*23_21은 새롭게 실행될 프로그램 이름*/
	printf("Running %s with execve\n", arg[0]);
	/*23_21에 envp에 설정된 환경 정보 전달 */
	execve("./23_21", arg, envp);
	printf("execve failed to run %s\n", arg[0]);
	exit(0);
}
