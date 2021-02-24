#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd, flag;
	struct{
		char name[15];
		char phone[15];
	}student;

	if((fd = open(argv[1], O_RDWR | O_CREAT, 0644)) == -1) {
		perror("open failed");
		exit(1);
	}
	/*파일 상태 정보를 알아내 flag에 저장*/
	if((flag=fcntl(fd, F_GETFL)) == -1) {
		perror("fcntl failed");
		exit(1);
	}

	/*상태 정보가 저장되어 있는 flag에 O_APPEND를 추가 */
	flag |= O_APPEND;
	/*fd 파일의 상태 정보를 flag로 설정 */
	if((fcntl(fd, F_SETFL, flag)) == -1) {
			perror("fcntl failed");
			exit(1);
	}

	while(1) {
		printf("input name => ");
		scanf("%s", student.name);
		if(!strcmp(student.name, "quit"))
			break;
		printf("input phone number => ");
		scanf("%s", student.phone);
		write(fd, (char *)&student, sizeof(student));
	}
	close(fd);
	exit(0);
}
