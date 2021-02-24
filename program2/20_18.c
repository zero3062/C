#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>

int main()
{
	struct passwd *pw;

	/* 패스워드 파일로부터 사용자 정보를 차례로 읽어 출력 */
	while(pw=getpwent()) {
		/* pw->pw_name은 사용자 계정, pw->pw_uid는 사용자 ID,
		   pw->pw_dir은 사용자의 홈 디렉토리를 의미 */
		printf("name:%s, uid:%d, home:%s\n", pw->pw_name, pw->pw_uid, pw->pw_dir);
	}
	/* 사용이 끝난 패스워드 파일을 닫음 */
	endpwent();
	exit(0);
}
