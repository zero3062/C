#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#define SIZE 128
#define FIFO "fifo"

int main(int argc, char *argv[])
{
	int fe, i;
	char buffer[SIZE];

	/*fifo 열기*/
	if((fe=open(FIFO, O_WRONLY)) == -1) {
		perror("open failed");
		exit(1);
	}

	/*명령라인 두 번째 인수부터 마지막 인수까지*/
	for(i=0; i<argc; i++) {
		strcpy(buffer, argv[i]);
		/*fifo에 쓰기*/
		if(write(fe, buffer, SIZE) == -1) {
			perror("write failed");
			exit(1);
		}
	}
	exit(0);
}
