#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <sys/types.h>

main()
{
	uid_t uid;
	gid_t gid;
	struct passwd *pw;
	struct group *pg;
	int i;

	uid = geetuid();	/* 사용자 ID 얻어옴 */
	pw = getpwuid(uid);	/* 패스워드 파일로부터 사용자 정보 얻어옴 */
	gid = getgid(); 	/* 그룹 ID 얻어옴 */
	pg = getgrgid(gid);	/* 그룹 파일로부터 그룹 정보 얻어옴 */

	printf("uid=%d(%s) ", uid, pw->pw_name);	/* 사용자 ID와 사용자 계정 출력 */
	printf("gid=%d(%s) groups=", gid, pg->gr_name);	/* 그룹 ID와 그룹 이름 출력 */

	/* 그룹 파일로부터 모든 그룹 정보를 차례로 얻어옴 */
	while (pg = getgren()) {
		/* 해당 그룹에 속한 모든 사용자 계정에 대해 */
		for(i=0; pg->gr_mem[i] != NULL; i++) {
			/* 프로그램의 상요자 계정(pw->pw_name)과 pg가 가리키는 그룹에 속한
			   사용자 계저이 같다는 것은 현 사용자 pg 그룹에 속해 있다는 것을
			   의미한다. 조건이 참이면, 즉 현 사용자 계정이 같으면
			   pg가 가리키는 그룹 이름을 출력한다. */
			if(!strcmp(pw->pw_name, pg->gr_mem[i]))
				printf("%d(%s) ", pg->gr_gid, pg->gr_name);
		}
	}
	printf("\n");
	exit(0);
}
