#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(symlink(argv[1], argv[2]) == -1) { /*argv[1]에 대한 심볼릭 링크 argv[2]를 생성*/
		perror("symlink failed");
		exit(1);
	}
	printf("link %s to %s\n", argv[1], argv[2]);
	exit(0);
}
