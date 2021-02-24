#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 7777   
#define MAXPENDING 5   
#define BUFSIZE 1024  

int main()
{
    int servSockfd;
    int clntSockfd;
    struct sockaddr_in servAddr;
    struct sockaddr_in clntAddr;
    char recvBuffer[BUFSIZE];
    int clntLen;
    int recvLen;
    pid_t processID;

    if((servSockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1) {
       perror("sock failed");
       exit(1);
   }

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(PORT);

    if(bind(servSockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1) {
       perror("bind failed");
       exit(1);
    }

    if(listen(servSockfd, MAXPENDING) == -1) {
       perror("listen failed");
       exit(1);
    }

    while(1) {
       clntLen = sizeof(clntAddr);
       if((clntSockfd=accept(servSockfd, (struct sockaddr*)&clntAddr, &clntLen)) == -1) {
          perror("accept failed");
          exit(1);
       }

       if((processID=fork()) == -1) {
          perror("fork failed");
          exit(1);
       } else if(processID == 0) {
          close(servSockfd);
          while(1) {
             if((recvLen=recv(clntSockfd, recvBuffer, BUFSIZE, 0)) == -1) {
                perror("recv failed");
                exit(1);
             }
             if(recvLen == 0)
                break;

             recvBuffer[recvLen] = '\0';
			 printf("Recevied: %s\n", recvBuffer);

             if(send(clntSockfd, recvBuffer, recvLen, 0) != recvLen) {
                perror("send failed");
                exit(1);
             }
          }
          close(clntSockfd);
          exit(0);
       }
 
       close(clntSockfd);
    }
}
