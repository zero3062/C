#include <stdio.h>
#include <stdlib.h>

/*envp에 환경 변수 정보 저장*/
int main(int argc, char *argv[], char *envp[])
{
	while(*envp)
		printf("%s\n", *envp++);
}
