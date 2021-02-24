#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define SIZE 124
#define PRIOR 10   /* 우선순위 최대값 */

struct {
    long type;
    char data[SIZE];
} msg_data;

main()
{
    int msqid, data_len;

    /* 1234 키의 메시지 큐가 있으면 접근해서 식별자 받음 */
    if(msqid = msgget((key_t)1234, IPC_CREAT|0666) == -1) {
       perror("msgget failed");
       exit(1);
    }

    while(1) {
       /* (-1*PRIOR)에 의해 메시지 큐에서 메시지 형식 값이 작은 메시지부터 읽음.
       IPC_NOWAIT에 의해 메시지 없으면 실패로 -1 반환하는데 이때의 errno는 ENOMSG */
       if((data_len=msgrcv(msqid, &msg_data, SIZE, (-1*PRIOR), IPC_NOWAIT)) == -1) {
          if(errno == ENOMSG) {
             printf("no message\n");
             break;
          }
          perror("msgrcv failed");
          break;
       }
       msg_data.data[data_len]='\0';
       printf("data : %s [%ld]\n", msg_data.data, msg_data.type);
    }

    /* msqid 메시지 큐 삭제 */
    if(msgctl(msqid, IPC_RMID, 0) == -1) {
       perror("msgctl failed");
       exit(1);
    }

    exit(0);
}