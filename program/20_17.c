#include <stdio.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

main()
{
	uid_t uid;
	struct passwd *pw;

	/* 실제 사용자 ID를 얻어옴 */
	uid = getuid();
	/* uid에 대한 사용자 정보를 얻어옴 */
	pw = getpwuid(uid);
	/* pw->pw_name는 사용자 계정, pw->pw_uid은 사용자 ID, pw->pw_gid는
	   사용자가 속한 그룹 ID, pw->pw_dir는 사용자의 홈 디렉토리를 의미 */
	printf("name:%s, uid:%d, gid:%d, home:%s\n", pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir);

	exit(0);
}
