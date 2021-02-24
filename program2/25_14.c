#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define SIZE 128	
#define FIFO "fifo"	

int main(int argc, char *argv[])
{
	int fd, i;
	char buffer[SIZE];

	/*FIFO 열기*/
	if((fd=open(FIFO, O_WRONLY))==-1) {
		perror("open failed");
		exit(1);
	}
	
	/*명령라인 두번째 인수부터 마지막 인수까지*/
	for(i=1;i<argc;i++) {
		strcpy(buffer, argv[i]);
		/*fifo에 쓰기*/
		if(write(fd, buffer,SIZE)==-1) {
			perror("write failed");
			exit(1);
		}
	}
	exit(0);
}
