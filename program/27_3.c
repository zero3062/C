#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 7777   /* ��Ʈ ��ȣ */
#define BUFSIZE 1024

main()
{
    int sockfd;
    struct sockaddr_in servAddr;
    struct sockaddr_in clntAddr;
    char recvBuffer[BUFSIZE];
    int clntLen;
    int recvLen;

    /* ���ͳ����� ����� ���μ����� ���� ����� �ϰ� UDP ����� �̿��ϴ� ������ ���� */
    if((sockfd=socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
       perror("sock failed");
       exit(1);
    }

    /* servAddr�� 0���� �ʱ�ȭ */
    memset(&servAddr, 0, sizeof(servAddr));
    /* servAddr�� IP �ּҿ� ��Ʈ ��ȣ�� ���� */
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(PORT);

    /* sockfd ���Ͽ� �ּ� ���� ���� */
    if(bind(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1) {
       perror("bind failed");
       exit(1);
    }

    /* ���� �ݺ� */
    while(1) {
       clntLen = sizeof(clntAddr);
       /* sockfd �������� ������ �����͸� �޾� recvBuffer�� �����ϰ�
          Ŭ���̾�Ʈ �ּ� ������ clntAddr�� ���� */
       if((recvLen=recvfrom(sockfd, recvBuffer, BUFSIZE-1, 0, (struct sockaddr*)&clntAddr, &clntLen)) == -1) {
          perror("recvfrom failed");
          exit(1);
       }
       recvBuffer[recvLen] = '\0';
       /* ���� �����͸� ��� */
       printf("Recevied: %s\n", recvBuffer);

       /* ���� �����͸� Ŭ���̾�Ʈ���� ���� */
       if(sendto(sockfd, recvBuffer, recvLen, 0, (struct sockaddr*)&clntAddr, sizeof(clntAddr)) != recvLen) {
          perror("sendto failed");
          exit(1);
       }
    }
}