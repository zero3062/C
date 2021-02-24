#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 7777   /* ��Ʈ ��ȣ */
#define MAXPENDING 5   /* Ŭ���̾�Ʈ �䱸�� ����ϴ� ť�� ũ�� */
#define BUFSIZE 1024   /* ������ ũ�� */

main()
{
    int servSockfd;
    int clntSockfd;
    struct sockaddr_in servAddr;
    struct sockaddr_in clntAddr;
    char recvBuffer[BUFSIZE];
    char sendBuffer[BUFSIZE];
    int clntLen;
    int recvLen;

    /* ���� ���� */
    if((servSockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1) {
       perror("sock failed");
       exit(1);
    }

    /* servAddr�� 0���� �ʱ�ȭ */
    memset(&servAddr, 0, sizeof(servAddr));
    /* servAddr�� �ּ� ���� ���� */
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(PORT);

    /* servSockfd ���Ͽ� �ּ� ���� ���� */
    if(bind(servSockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1) {
       perror("bind failed");
       exit(1);
    }

    /* servSockfd �������� ������ Ŭ���̾�Ʈ ��û ��ٸ� */
    if(listen(servSockfd, MAXPENDING) == -1) {
       perror("listen failed");
       exit(1);
    }

    /* ���� �ݺ� */
    while(1) {
       clntLen = sizeof(clntAddr);
       /* servSockfd �������� ������ Ŭ���̾�Ʈ ��û �޾Ƶ��� */
       if((clntSockfd=accept(servSockfd, (struct sockaddr*)&clntAddr, &clntLen)) == -1) {
          perror("accept failed");
          exit(1);
       }
       printf("client is in\n");
       /* �ڽ� ���μ��� ���� */
       switch(fork()) {
          case -1:
             perror("fork failed");
             exit(1);

          /* �ڽ� ���μ����� */
          case 0:
             close(servSockfd);
             /* ������ Ŭ���̾�Ʈ�� ���� �ݺ� */
             while(1) {
                /* clntSockfd �������� ������ �����͸� �޾� recvBuffer�� ���� */
                if((recvLen=recv(clntSockfd, recvBuffer, BUFSIZE, 0)) == -1) {
                   perror("recv failed");
                   exit(1);
                }
                /* Ŭ���̾�Ʈ�� ������ ������ recv�� 0�� ��ȯ */
                if(recvLen == 0)
                   break;

                recvBuffer[recvLen] = '\0';
                /* ���� �����͸� ��� */
                printf("%s\n", recvBuffer);
             }
             close(clntSockfd);
             exit(0);

          /* �θ� ���μ����� */
          default:
             while(1) {
                /* �͹̳ηκ��� ������ �Է� */
                fgets(sendBuffer, BUFSIZE, stdin);

                /* �Է¹��� �����͸� Ŭ���̾�Ʈ���� ���� */
                if(send(clntSockfd, sendBuffer, strlen(sendBuffer), MSG_NOSIGNAL) != strlen(sendBuffer)) {
                   /* ������ ������ ���� ȣ�⿡ �����ϸ� errno���� EPIPE�� ���� */
                   if(errno == EPIPE) {
                      printf("client is out\n");
                      break;
                   }
                   perror("send failed");
                   exit(1);
                }
             }
       }
       close(clntSockfd);
    }
}