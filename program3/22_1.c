#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
	struct stat st;

	if(stat(argv[1], &st) == -1) {
		perror("stat failed");
		exit(1);
	}
	printf("%ld byte, user-id %d, group-id %d, modify time %s", st.st_size, st.st_uid, st.st_gid, ctime(&st.st_mtime));
	exit(0);
}
