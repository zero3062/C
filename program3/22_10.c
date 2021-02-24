#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
	DIR *dp;

	if(mkdir("dir", 0755)==-1){
		perror("mkdir failed");
		exit(1);
	}
	if((dp=opendir("dir")) == NULL) {
		perror("opendir failed");
		exit(1);
	}
	closedir(dp);
	exit(0);
}
