#include <stdio.h>
#include <unistd.h>

main(int argc, char *argv[])
{
	if(remove(argv[1])==-1) {	/* argv[1]을 삭제 */
		perror("remove failed");
		exit(1);
	}
	printf("remove %s\n", argv[1]);
	exit(0);
}
