#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct stat st;

	if(stat(argv[1], &st) == -1) {
		perror("stat failed");
		exit(1);
	}

	/*(st.st_mode & S_IRUSR)은 소유자에게 읽기 권한이 있는지를 
	  알아내는 식으로 참이면 "read"가 선택되고 거짓이면 ""이 선택*/
	printf("user: %s%s%s\n", (st.st_mode & S_IRUSR)?"read":"",(st.st_mode & S_IWUSR) ? "write ":"", (st.st_mode & S_IXUSR)?"execute":"");
	printf("group: %s%s%s\n", (st.st_mode & S_IRGRP)?"read":"",(st.st_mode & S_IWGRP)? "write ":"", (st.st_mode & S_IXGRP)?"execute":"");
	printf("other: %s%s%s\n", (st.st_mode &S_IROTH)?"read":"", (st.st_mode & S_IWOTH)?"write":"", (st.st_mode & S_IXOTH)?"execute":"");

	exit(0);
}
