#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 7777 /*서버의 포트 번호*/
#define BUFSIZE 1024

/*argv[1]은 수와 점 표기의 IP주소*/
int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in servAddr;
	char sendBuffer[BUFSIZE] , recvBuffer[BUFSIZE];
	socklen_t recvLen=0, servLen=0;

	if(argc != 2) {
		fprintf(stderr, "Usage: %s IP_address\n", argv[0]);
		exit(1);
	}

	/*소켓 생성*/
	if((sockfd=socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("sock failed");
		exit(1);
	}

	memset(&servAddr, 0, sizeof(servAddr));
	/*servAddr에 IP주소와 포트 번호 저장 */
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	servAddr.sin_port = htons(PORT);
	
	/*quit를 입력받을 때까지 반복*/
	while(1){
		printf("Input sending message ==> ");
		fgets(sendBuffer, BUFSIZE, stdin);
		if(!strncmp(sendBuffer, "quit", 4))
			break;

	/*sockfd 소켓을 통해 servAddr을 주소로 갖는 서버에게 데이터를 보냄*/
	if(sendto(sockfd, sendBuffer, strlen(sendBuffer), 0, (struct socketaddr *)&servAddr, sizeof(servAddr))!= strlen(sendBuffer)) {
		perror("sendto failed");
		exit(1);
	}

	servLen = sizeof(servLen);
	/*sockfd 소켓을 통해 들어오는 데이터를 받아 recvBuffer에 저장*/
	if((recvLen==recvfrom(sockfd, recvBuffer, BUFSIZE-1, 0, (struct sockaddr *)&servAddr, &servLen)) != strlen(sendBuffer)) {
		perror("recvfrom failed");
		exit(1);
	}

		recvBuffer[recvLen] = '\0';
		/*받은 데이터를 출력*/
		printf("Received: %s\n", recvBuffer);
	}

	close(sockfd);
	exit(0);
}

