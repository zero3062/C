#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#define SIZE 124

void signalHandler(int signo);


struct {
	long type;
	char data[SIZE];
} msg_data={1, "Linux C Programming"};
int msqid;

int main()
{
	if(msqid=msgget((key_t)1234, IPC_CREAT|0666)==-1) {
		perror("msgget failed");
		exit(1);
	}

	if(msgsnd(msqid, &msg_data, strlen(msg_data.data), 0) == -1) {
       perror("msgsnd failed");
       exit(1);
	}

	signal(SIGINT, signalHandler);
	pause();
}

void signalHandler(int signo)
{
	if(msgctl(msqid,IPC_RMID,0)==-1) {
		perror("msgctl failed");
		exit(1);
	}
	exit(0);
}
