#include <stdio.h>
#include <stdlib.h>

/*environ에 환경 변수 정보 저장*/
extern char **environ;

int main(int argc, char *argv[])
{
	printf("my environment cariables are :\n");
	while(*environ)
		printf("%s\n", *(environ++));
	exit(0);
}
