#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define SIZE 124
/* �޽��� ������ �����ϴ� type ����� �켱������ �����ϴ� �뵵�� ����Ѵ�. */
struct {
    long type;
    char data[SIZE];
} msg_data;

main()
{
    int msqid, data_len;
    char buffer[SIZE];

    /* 1234 Ű�� �޽��� ť ���� */
    if(msqid = msgget((key_t)1234, IPC_CREAT|0666) == -1) {
       perror("msgget failed");
       exit(1);
    }

    while(1) {
       /* ǥ���Է���ġ�κ��� ������ �Է� */
       printf("input data => ");
       scanf("%s", buffer);
       /* �Է¹��� ������ ��quit���̸� while �� ��� */
       if(!strcmp(buffer, "quit"))
          break;
       /* ǥ���Է���ġ�κ��� �켱���� �Է� */
       printf("input priority => ");
       scanf("%ld", &(msg_data.type)); 
       strcpy(msg_data.data, buffer);
       /* msg_data �޽����� msqid �޽��� ť�� ���� */
       if(msgsnd(msqid, &msg_data, strlen(msg_data.data), 0) == -1) {
          perror("msgsnd failed");
          exit(1);
       }
    }
    exit(0);
}
