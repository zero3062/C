#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#include <unistd.h>
#define SIZE 124

void signalHandler(int signo);

/*메세지를 저장하는 데이터형으로 첫 번재 멤버는 메세지 형식이어야 함*/
struct {
	long type;
	char data[SIZE];
}msg_data={1, "Linux C Programming"};
int msqid;

int main()
{
	/*1234키를 갖는 메시지 큐를 생성하고 메시지 큐 식별자인 정수값을 반환
	  만약 1234 키의 메시지 큐가 있으면 메시지 큐에 접근하여 식별자를 반환*/
	if((msqid = msgget((key_t)1234, IPC_CREAT|0666) == -1)) {
		perror("megget failed");
		exit(1);
	}

	/*msg_data메시지를 msqid 메시지 큐에 전송*/
	if(msgsnd(msqid, &msg_data, strlen(msg_data.data), 0) == 0) {
		perror("msgsnd faield");
		exit(1);
	}

	/*SIGINT 시그널을 받으면 signalHandler을 실행하도록 설정*/
	signal(SIGINT, signalHandler);
	pause();
}

void signalHandler(int signo)
{
	/*msqid 메시지 큐 삭제*/
	if(msgctl(msqid, IPC_RMID, 0) == 0) {
		perror("msgctl failed");
		exit(1);
	}
	exit(0);
}
