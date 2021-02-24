#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
	DIR *dp;
	struct dirent *dirp;

	if((dp=opendir(".")) == NULL) {
		perror("opendir failed");
		exit(1);
	}
	while(dirp=readdir(dp)) {
		printf("%s ", dirp->d_name);
	}
	printf("\n");
	closedir(dp);
	exit(0);
}
