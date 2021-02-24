#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>

int main()
{
	struct passwd *pw;

	while(pw=getpwent()) {
		printf("name:%s, uid:%d, home:%s\n", pw->pw_name, pw->pw_uid, pw->pw_dir);
	}
	endpwent();
	exit(0);
}