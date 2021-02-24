#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define PORT 7777   /* ������ ��Ʈ ��ȣ */
#define BUFSIZE 1024   /* ������ ũ�� */

void signalHandler(int signo);
int sockfd;

/* argv[1]�� ���� �� ǥ���� IP �ּ� */
main(int argc, char *argv[])
{
    struct sockaddr_in servAddr;
    char sendBuffer[BUFSIZE], recvBuffer[BUFSIZE];
    int recvLen;
    pid_t pid;

    if(argc != 2) {
       fprintf(stderr, "Usage: %s IP_address\n", argv[0]);
       exit(1);
    }

    /* ���� ���� */
    if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1) {
       perror("sock failed");
       exit(1);
    }

    /* servAddr�� 0���� �ʱ�ȭ */
    memset(&servAddr, 0, sizeof(servAddr));
    /* servAddr�� �ּ� ���� ���� */
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(argv[1]);
    servAddr.sin_port = htons(PORT);

    /* servAddr ������ ����� ��û */
    if(connect(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1) {
       perror("connect failed");
       exit(1);
    }

    /* �ڽ� ���μ��� ���� */
    switch(pid=fork()) {
       case -1:
          perror("fork failed");
          exit(1);

       /* �ڽ� ���μ����� */
       case 0:
          /* SIGINT �ñ׳� ������ signalHandler �����ϵ��� ���� */
          signal(SIGINT, signalHandler);
          /* SIGINT �ñ׳� ���� ������ �ݺ� */
          while(1) {
             /* sockfd �������� ������ �����͸� �޾� recvBuffer�� ���� */
             if((recvLen=recv(sockfd, recvBuffer, BUFSIZE, 0)) == -1) {
                perror("recv failed");
                exit(1);
             }

             recvBuffer[recvLen] = '\0';
             /* ���� �����͸� ��� */
             printf("%s\n", recvBuffer);
          }
          break;

       /* �θ� ���μ����� */
       default:
          /* quit�� �Է� ���� ������ �ݺ� */
          while(1) {
             /* �͹̳ηκ��� ������ �Է� */
             fgets(sendBuffer, BUFSIZE, stdin);

             if(!strncmp(sendBuffer, "quit", 4)) {
                /* �ڽ� ���μ������� SIGINT �ñ׳� ���� */
                kill(pid, SIGINT);
                break;
             }

             /* �Է¹��� �����͸� �������� ���� */
             if(send(sockfd, sendBuffer, strlen(sendBuffer), 0) != strlen(sendBuffer)) {
                perror("send failed");
                exit(1);
             }
          }
    }
    close(sockfd);
    exit(0);
}

 /* SIGINT �ñ׳� ������ ����� �ڵ鷯 */
void signalHandler(int signo)
{
    close(sockfd);
    exit(0);
}