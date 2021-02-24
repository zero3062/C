#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define SIZE 124
#define PRIOR 10   /* �켱���� �ִ밪 */

struct {
    long type;
    char data[SIZE];
} msg_data;

main()
{
    int msqid, data_len;

    /* 1234 Ű�� �޽��� ť�� ������ �����ؼ� �ĺ��� ���� */
    if(msqid = msgget((key_t)1234, IPC_CREAT|0666) == -1) {
       perror("msgget failed");
       exit(1);
    }

    while(1) {
       /* (-1*PRIOR)�� ���� �޽��� ť���� �޽��� ���� ���� ���� �޽������� ����.
       IPC_NOWAIT�� ���� �޽��� ������ ���з� -1 ��ȯ�ϴµ� �̶��� errno�� ENOMSG */
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

    /* msqid �޽��� ť ���� */
    if(msgctl(msqid, IPC_RMID, 0) == -1) {
       perror("msgctl failed");
       exit(1);
    }

    exit(0);
}