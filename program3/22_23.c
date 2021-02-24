#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	if(chroot("/home/jkim/book/linux/chap22") == -1) {
		perror("chroot failed");
		exit(1);
	}
	if(chdir("/")==-1) {
		perror("chdir failed");
		exit(1);
	}
	if(mkdir("rootsub", 0777)==-1) {
		perror("mkdir failed");
		exit(1);
	}
	exit(0);
}
