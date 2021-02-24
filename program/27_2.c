#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 7777   /* ������ ��Ʈ ��ȣ */
#define BUFSIZE 1024

/* argv[1]�� ���� �� ǥ���� IP �ּ� */
main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servAddr;
    char sendBuffer[BUFSIZE], recvBuffer[BUFSIZE];
    int recvLen;

    if(argc != 2) {
       fprintf(stderr, "Usage: %s IP_address\n", argv[0]);
       exit(1);
    }

    /* ���� ���� */
    if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1) {
       perror("sock failed");
       exit(1);
    }

    memset(&servAddr, 0, sizeof(servAddr));
    /* servAddr�� IP �ּҿ� ��Ʈ ��ȣ�� ���� */
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(argv[1]);
    servAddr.sin_port = htons(PORT);

    /* servAddr ������ ����� ��û */
    if(connect(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1) {
       perror("connect failed");
       exit(1);
    }

    /* quit�� �Է� ���� ������ �ݺ� */
    while(1) {
       printf("Input sending message ==> ");
       fgets(sendBuffer, BUFSIZE, stdin);
       if(!strncmp(sendBuffer, "quit", 4))
          break;

       /* sockfd ������ ���� �����͸� ���� */
       if(send(sockfd, sendBuffer, strlen(sendBuffer), 0) != strlen(sendBuffer)) {
          perror("send failed");
          exit(1);
       }

       /* sockfd ������ ���� ������ �����͸� �޾� recvBuffer�� ���� */
       if((recvLen=recv(sockfd, recvBuffer, BUFSIZE-1, 0)) <= 0) {
          perror("recv failed");
          exit(1);
       }

       recvBuffer[recvLen] = '\0';
       /* ���� �����͸� ��� */
       printf("Recevied: %s\n", recvBuffer);
    }
    /* sockfd ������ ���� */
    close(sockfd);
    exit(0);
}