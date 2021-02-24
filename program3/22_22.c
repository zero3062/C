#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat st;

	if(stat(argv[1], &st) == -1) {	
		perror("stat failed");
		exit(1);
	}
	if(chown(argv[2], st.st_uid, st.st_gid) == -1 ) {
		perror("chown failed");
		exit(1);
	}
	exit(0);
}
