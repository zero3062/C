#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	/* 실제 사용자 ID를 알아냄 */
	printf("Userid : %d\n", getuid());
	/* 실제 그룹 ID를 알아냄 */
	printf("Groupid : %d\n", getgid());
	exit(0);
}
