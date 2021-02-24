#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SIZE 256

int main()
{
	char read_buffer[SIZE], write_buffer[SIZE];
	int pipes1[2], pipes2[2], length;

	/*두 개의 파이프 생성*/
	if(pipe(pipes1)==-1 || pipe(pipes2)==-1) {
		perror("pipe failed");
		exit(1);
	}
	
	/*부모 프로세스는*/
	if(fork()) {
		/*pipes1의 쓰기 파일 식별자 닫기*/
		close(pipes1[1]);
		/*pipes2의 읽기 파일 식별자 닫기*/
		close(pipes2[0]);
		
		/*pipes1 파이프로부터 데이터 읽기*/
		if((length=read(pipes1[0], read_buffer, SIZE)) == -1) {
			perror("read failed");
			exit(1);
		}
		write(STDOUT_FILENO, "receive message: ", strlen("receive message: "));
		write(STDOUT_FILENO, read_buffer, length);

		sprintf(write_buffer, "Hi client!\n");
		/*pipes2 파이프에 데이터 쓰기*/
		write(pipes2[1], write_buffer, strlen(write_buffer));

		/*자식 프로세스가 종료되기를 기다림*/
		wait(NULL);
	/*자식 프로세스는*/
	} else {
		/*pipes1의 읽기 파일 식별자 닫기*/
		close(pipes1[0]);
		/*pipes2의 쓰기 파일 식별자 닫기*/
		close(pipes2[1]);

		sprintf(write_buffer, "Hi server!\n");
		/*pipes1 파이프에 데이터 쓰기*/
		write(pipes1[1], write_buffer, strlen(write_buffer));

		/*pipes2 파이프로부터 데이터 읽기*/
		if((length=read(pipes2[0], read_buffer, SIZE)) == -1) {
			perror("read failed");
			exit(1);
		}
		write(STDOUT_FILENO, "receive message: ", strlen("receive message: "));
		write(STDOUT_FILENO, read_buffer, length);
	}
	exit(0);
}
