#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAXLINE  511
#define MAX_SOCK 1024

char *EXIT_STRING = "exit";
char *START_STRING = "Connected to chat_server \n"; 

int maxfdp1;
int num_user = 0;
int clisock_list[MAX_SOCK];
int listen_sock;

void addClient(int s, struct sockaddr_in *newcliaddr);
int getmax();
void removeClient(int s);
void errquit(char *mesg) { perror(mesg); exit(1); }

void *thread_function(void *arg) {
	int i;
	printf("채팅 시작\n");
	while (1) {
		char bufmsg[MAXLINE + 1];
		printf("server>");
		fgets(bufmsg, MAXLINE, stdin); 
		if (!strcmp(bufmsg, "\n")) continue; 
	}
}

int main(int argc, char *argv[]) {
	
	struct sockaddr_in servaddr;
	struct sockaddr_in cliaddr;
	char buf[MAXLINE + 1]; 
	int sd, i, j, nbyte, accp_sock, addrlen = sizeof(struct sockaddr_in);
	fd_set read_fds;
	pthread_t a_thread;

	if (argc != 2) {
		printf("사용법 :%s port\n", argv[0]);
		exit(0);
	}

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd == -1) {
		perror("socket fail");
		exit(1);
	}
	bzero((char *)&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(10000);

	if (bind(sd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("bind fail");  exit(1);
	}
	listen(sd, 5);
	
	listen_sock = sd;
	pthread_create(&a_thread, NULL, thread_function, (void *)NULL);
	
	while (1) {
		FD_ZERO(&read_fds);
		FD_SET(listen_sock, &read_fds);
		for (i = 0; i < num_user; i++)
			FD_SET(clisock_list[i], &read_fds);

		maxfdp1 = getmax() + 1;
		if (select(maxfdp1, &read_fds, NULL, NULL, NULL) < 0)
			errquit("select fail");

		if (FD_ISSET(listen_sock, &read_fds)) {
			accp_sock = accept(listen_sock,
				(struct sockaddr*)&cliaddr, &addrlen);
			if (accp_sock == -1) errquit("accept fail");
			addClient(accp_sock, &cliaddr);
			send(accp_sock, START_STRING, strlen(START_STRING), 0);
			write(1, "\033[0G", 4);
			printf("현재 참가자 수 = %d\n", num_user);
			fprintf(stderr, "server>");
		}

		for (i = 0; i < num_user; i++) {
			if (FD_ISSET(clisock_list[i], &read_fds)) {
			
				nbyte = recv(clisock_list[i], buf, MAXLINE, 0);
				if (nbyte <= 0) {
					removeClient(i);
					continue;
				}
				buf[nbyte] = 0;
				
				if (strstr(buf, EXIT_STRING) != NULL) {
					removeClient(i);
					continue;
				}
				for (j = 0; j < num_user; j++)
					if(j!=i){ send(clisock_list[j], buf, nbyte, 0);}
				printf("%s", buf);
				fprintf(stderr, "server>");
			}
		}
	}
	return 0;
}

void addClient(int s, struct sockaddr_in *newcliaddr) {
	char buf[20];
	inet_ntop(AF_INET, &newcliaddr->sin_addr, buf, sizeof(buf));
	write(1, "\033[0G", 4);
	printf("new client: %s\n", buf);
	clisock_list[num_user] = s;
	num_user++;
}

void removeClient(int s) {
	close(clisock_list[s]);
	if (s != num_user - 1) {
		clisock_list[s] = clisock_list[num_user - 1];
	}
	num_user--;
	write(1, "\033[0G", 4);
	printf("채팅 참가자 1명 탈퇴. 현재 참가자 수 = %d\n", num_user);
	fprintf(stderr, "server>");
}

int getmax() {
	int max = listen_sock;
	int i;
	for (i = 0; i < num_user; i++)
		if (clisock_list[i] > max)
			max = clisock_list[i];
	return max;
}
