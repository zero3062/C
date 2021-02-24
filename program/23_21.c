#include <stdio.h>

/*environ에 환경 변수 정보 저장*/
extern char **environ;

main(int argc, char *argv[])
{
	char **env=environ;
	printf("my environment variables are :\n");
	while(*env)
		printf("%s\n", *(env++));
	exit(0);
}
