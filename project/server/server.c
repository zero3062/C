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
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

char *nextword(char **s) //뛰어쓰기를 기준으로 문장을 끊는다.
{       
    char *rs;
    for(; **s==' '; (*s)++);
    rs = *s;
    for(; **s != ' '  && **s; (*s)++);
    if(**s==' '){ **s=0; (*s)++;}
    return rs;
}

char *read_extension(char *buf, int size, char *test) //파일 확장자 형식에 맞게 buf를 바꿔준다.
{ //test는 파일 확장자명을 의미하고 size는 sizeof(buf)를 의미
	printf("%d %s\n", __LINE__, test);
	char *ctype = "text/html"; //ctype은 content-type을 의미한다.

	if(test == NULL || strcmp(test, ".html") == 0) { //만약 test가 NULL이거나 html이면
		ctype = "text/html";	
	} else if(strcasecmp(test, ".jpeg") == 0 || strcasecmp(test, ".jpg") == 0 || strcasecmp(test, ".jpe") == 0) { //test의 형식이 위와 같다면, strcasecmp는 대소문자 구별없이 구분
		ctype = "image/jpeg";
	} else if(strcmp(test, ".pdf") == 0) {
		ctype = "application/pdf";
	} else if(strcmp(test, ".zip") == 0) {
		ctype = "application/zip";	
	} else if(strcmp(test, ".gif") == 0) {
		ctype = "image/gif";
	} else if(strcmp(test, ".png") == 0) {
		ctype = "image/png";
	} 
	
	printf("%d %s %s\n", __LINE__, test, ctype);
	
	bzero(buf, size); //buf를 size의 크기로 초기화
	//buf에 해당 문구를 넣는다. contnet-type은 ctype으로 넣어준다.
	snprintf(buf, size-3,  "HTTP/1.1 200 OK\n"
			"Content-Type: %s; charset=utf-8\n\n", ctype);
	
	return buf;	
}

int read_fcont(char *fpath, char **fbuf) //fpath의 해당하는 파일의 사이즈를 반환하는 함수
{
	int fsize;
	int fd, re;
	struct stat statbuf;

	re = lstat(fpath, &statbuf); //fpath의 파일 정보를 읽어옴
	
	if(re< 0) {
		printf("%d lstat failed(%s)\n", __LINE__, strerror(errno));
		return -1;
	}
	fsize = statbuf.st_size; //fsize에 파일의 크기를 저장

	printf("%d file size : %d\n", __LINE__, fsize);

	*fbuf = malloc(fsize); //fbuf를 동적으로 할당
	bzero(*fbuf, fsize); //fbuf를 fsize만큼 초기화

	fd = open(fpath, O_RDONLY, 0644); //fpath의 파일을 열음
	if(fd < 0) 
		return -1;

	read(fd, *fbuf, fsize); //fbuf에 fsize만큼 파일을 읽어옴

	return fsize;
}

int http_func(int sfd)
{
	char buf[4096];
	char fpath[2048];
	char *fbuf;
	int fsize, i;
	char *s;
	char *ns;
	char *test;
	
	bzero(buf, sizeof(buf));
	bzero(fpath, sizeof(fpath));

	read(sfd, buf, sizeof(buf)); //buf에 socket에서 읽어와 buf의 크기만큼 넣음
	printf("=====================================\n");
	
	for(s=buf, i=0; ;i++) { //nextword함수를 이용하여 경로 가져오기
		ns=nextword(&s); //ns에 nextword함수를 이용해 경로를 찾는다
		if(i==1) { //GET /(경로) HTTP/1.1 이런식으로 나오기에 i가 1이면 break;로 빠져나옴.
			printf("%s\n", ns);
			break;
		}
	} 
	
	strcpy(fpath, "/home/sungjin/html"); //fpath를 해당 디렉토리 경로로 복사한다.
	
	if((strcmp(ns, "/") == 0) || (strcmp(ns, "") == 0)) { //"/"일 경우 fpath 뒤에 index.html을 붙인다..
		strcat(fpath, "/index.html");
	} else { //아닐 경우 ns를, 즉 경로를 붙여넣는다.
		strcat(fpath, ns);
	}
	
	test  = strrchr(ns, '.'); //strrchr 문자열 뒤에서 앞쪽으로 문자 검색
	
	printf("%d %s\n", __LINE__, test);
		
	printf("%d fpath : %s\n", __LINE__, fpath);

	fsize = read_fcont(fpath, &fbuf); //fpath의 경로에 해당하는 파일의 사이즈를 fsize에 저장

	if(fsize < 0)
		return 0;

	printf("%d %s\n", __LINE__, test);

	//해당 함수로 파일 확장자 형식에 맞게 buf를 반환받는다.
	read_extension(buf, sizeof(buf), test); 
	
	//buf를 소켓으로 불러온 sfd에 입력한다.
	write(sfd, buf, strlen(buf));
	//fbuf를 sfd에 입력한다.
	write(sfd, fbuf, fsize);
	
	//fbuf의 동적할당을 풀어준다.
	free(fbuf);
	fbuf=NULL;
	return 0;
}

int main(int argc, char *argv[]) 
{
	struct sockaddr_in cliaddr, servaddr;
	int sfd, sd, option=1;
	socklen_t addrlen = sizeof(struct sockaddr_in);

	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket fail");
		exit(1);
	}
	
	//소켓을 꺼도 자동으로 포트가 죽게 만드는 함수
	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(8000);
	
	if (bind(sd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("bind fail");  exit(1);
	}

	listen(sd, 5);
	
	while(1) {
		sfd = accept(sd, (struct sockaddr*)&cliaddr, &addrlen);
		http_func(sfd);
		close(sfd);
	}
	
	close(sd);

	return 0;
}
