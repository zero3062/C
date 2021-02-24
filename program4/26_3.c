#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define SIZE 124
/*메시지 형식을 저장하는 type 멤버를 우선순위를 저장하는 용도로 사용한다. */
struct {
	long type;
	char data[SIZE];
}msg_data;

int main()
{
	int msqid;
	char buffer[SIZE];

	/*1234 키의 메시지 큐 생성*/
	if((msqid = msgget((key_t)1234, IPC_CREAT|0666) == -1)) {
			perror("msgget failed");
			exit(1);
	}

	while(1) {
		/*표준 입력 장치로부터 데이터 입력*/
		printf("input data => ");
		scanf("%s", buffer);
		/*입력받은 내용이 'quit'면 while 문 벗어남*/
		if(!strcmp(buffer, "quit"))
			break;
		/*표준 입력 장치로부터 우선순위 입력*/
		printf("input proirity => ");
		scanf("%ld", &(msg_data.type));
		strcpy(msg_data.data, buffer);
		/* msg_data 메시지를 msqid 메시지 큐에 전송*/
		if(msgsnd(msqid, &msg_data, strlen(msg_data.data), 0) == -1) {
			perror("msgsnd failed");
			exit(1);
		}
	}
	exit(0);
}
