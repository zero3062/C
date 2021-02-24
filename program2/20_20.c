#include <stdio.h>
#include <stdlib.h>
#include <grp.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	gid_t gid;
	struct group *pg;
	int i;

	/* 그룹 ID를 얻음 */
	gid = getgid();
	/* 그룹 정보를 얻음 */
	pg = getgrgid(gid);
	printf("group name : %s\n", pg->gr_name);	/* pg->gr_name은 그룹의 이름 */
	exit(0);
}
