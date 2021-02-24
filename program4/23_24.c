#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Running ls with sysrem\n");
	/*system을 이용해 ls 명령어 실행*/
	system("ls");
	printf("Done\n");
	exit(0);
}
