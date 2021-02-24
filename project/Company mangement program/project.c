#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 1024

struct Company {
	char name[128];
	char address[256];
	int employee;
	char CEO[128];
	char field[256];
};

int count = 0;

void struct_count();
void new_create(struct Company *data);
void get_company(struct Company *cp);
void get_list(int count);

int main()
{
	char button;
	struct Company dat[count];

	struct_count();
	printf("count : %d\n", count);
	
	printf("기업관리 프로젝트\n\n");

	printf("입력받는 화면(n)\n");
	printf("리스트 출력(l)\n");
	printf("프로그램 종료(q)\n\n");
	
	printf("메인 화면 입력 : ");

	while(1) {
		scanf("%c", &button);
		
		if(button =='q')
			break;
		else if (button == 'n') {
			printf("\n");
			new_create(&dat[count]);
			count++;
			printf("메인 화면 입력 : ");
		} else if(button == 'l') {
			printf("\n");
			get_list(count);
			printf("메인 화면 입력 : ");
		} 
	}

	return 0;
}

void struct_count()
{
	int fp;
	char line[SIZE]; 
	ssize_t rd_size;
	int test = 0;
	if((fp=open("company.txt", O_RDONLY, 0644))==-1)
		printf("file error!\n");

	
	while(0<(rd_size = read(fp, line, SIZE-1))) {
		line[rd_size] = '\0';
		if(strstr(line, "{")!=NULL) {
			test++;
		}
	}
	printf("\n");
	
	close(fp);
	printf("test '{' : %d\n", test);
	count = test;

}

void new_create(struct Company *data)
{	
	printf("기업을 입력해주세요\n");
	int fp, i;
	char info[5][15] = {"name : ", "address : ", "employee : ", "CEO : ", "field : "};
	char *buf;
	buf=calloc(256, sizeof(char *));

	fp =open("company.txt", O_RDWR | O_APPEND, 0644);
	if(fp==-1)
		printf("file Error!\n");
	
	char *start = "{\n";
	write(fp, start, strlen(start));

	for(i=0;i<5;i++) {
		char *str = malloc(sizeof(char) * 256);
		strcpy(str, "\t");
		if(i==0)
			getchar();

		printf("%s", info[i]);
		fgets(buf, 256, stdin);
		buf[strlen(buf) - 1] = '\0';

		strcat(str, info[i]);
		strcat(str, buf);
		strcat(str, ",\n");
		
		write(fp, str, strlen(str));
		
		free(str);
	}
	
	char *end = "},\n";
	write(fp, end, strlen(end));


	close(fp);
	printf("\n");
}

void get_company(struct Company *com)
{	
	char ch;

	printf("\n");
	
	printf("---------------------------------\n");
	printf("|%10s|%20s|\n", "name", com->name);
	printf("---------------------------------\n");
	printf("|%10s|%20s|\n", "address", com->address);
	printf("---------------------------------\n");
	printf("|%10s|%20d|\n", "employee", com->employee);
	printf("---------------------------------\n");
	printf("|%10s|%20s|\n", "CEO", com->CEO);
	printf("---------------------------------\n");
	printf("|%10s|%20s|\n", "field", com->field);
	printf("---------------------------------\n");
	
	printf("\n수정하기(e)\n");
	printf("나가기(q)\n");
	printf("회사 정보 화면 입력 : ");

	while(1) {
		scanf("%c", &ch);
		if(ch == 'e') {
			printf("edit\n");
			printf("\n회사 정보 화면 입력 : ");
		} else if(ch=='q') {
			break;
		} 
	}
}

void get_list(int count)
{
	struct Company read[count];
	FILE *fp;
	fp = fopen("company.txt", "r");
	
	char n;

	for(int i =0;i<count;i++) 
		fscanf(fp, "%s %s %d %s %s", read[i].name, read[i].address, &read[i].employee, read[i].CEO, read[i].field);
	
	fclose(fp);
	
	printf("------------------------------------------------------------------\n");
	printf("|%3s |%10s |%10s |%10s |%10s |%10s|\n", "Num", "Name", "Address", "Employee", "CEO", "Field");
	
	printf("------------------------------------------------------------------\n");

	for(int i =0;i<count;i++) {
		printf("|%3d |%10s |%10s |%10d |%10s |%10s|\n", i+1, read[i].name, read[i].address, read[i].employee, read[i].CEO, read[i].field);
		printf("------------------------------------------------------------------\n");
	}

	printf("\n");
	
	printf("회사 정보 보기(숫자)\n");
	printf("나가기(q)\n");
	
	printf("리스트 화면 입력 : ");

	while(1) {
		scanf("%c", &n);

		if(isdigit(n)==0) {
			if(n=='q') {
				break;
			}
		} else {
			get_company(&read[(n-'0')-1]);
			printf("\n리스트 화면 입력 : ");
		}
	}
}
