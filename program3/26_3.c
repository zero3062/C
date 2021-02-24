#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define SIZE 124
struct {
    long type;
    char data[SIZE];
} msg_data;

int main()
{
    int msqid, data_len;
    char buffer[SIZE];

    if(msqid = msgget((key_t)1234, IPC_CREAT|0666) == -1) {
       perror("msgget failed");
       exit(1);
    }

    while(1) {
       printf("input data => ");
       scanf("%s", buffer);
       if(!strcmp(buffer, "quit"))
          break;
       printf("input priority => ");
       scanf("%ld", &(msg_data.type)); 
       strcpy(msg_data.data, buffer);
       if(msgsnd(msqid, &msg_data, strlen(msg_data.data), 0) == -1) {
          perror("msgsnd failed");
          exit(1);
       }
    }
    exit(0);
}
