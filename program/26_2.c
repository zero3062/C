#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#define SIZE 124

struct {
    long type;
    char data[SIZE];
} msg_data;

main()
{
    int msqid;
    struct msqid_ds msg_stat;

    /* 1234 키의 메시지 큐가 있으면 접근해서 식별자 받음*/
    if(msqid = msgget((key_t)1234, IPC_CREAT|0666) == -1) {
       perror("msgget failed");
       exit(1);
    }

    /* msqid 메시지큐에서 메시지를 읽어 msg_data에 저장*/
    if(msgrcv(msqid, &msg_data, SIZE, 0, 0) == -1) {
       perror("msgrcv failed");
       exit(1);
    }

    printf("data read from message queue : %s\n", msg_data.data);

    /* msqid 메시지 큐 정보를 얻어 msg_stat에 저장*/
    if(msgctl(msqid, IPC_STAT, &msg_stat) == -1) {
       perror("msgctl failed");
       exit(1);
    }
    /* msg_stat.msg_lspid 프로세스에게 SIGINT 시그널을 보냄*/
    kill(msg_stat.msg_lspid, SIGINT);

    exit(0);
}
