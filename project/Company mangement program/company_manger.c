#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

struct Company {
	char name[128];
	char address[256];
	int employee;
	char CEO[128];
	char field[256];
};

typedef struct Korea_Check {
	int len;
	int kor_len;
	int eng_len;
	int blk_len;
	int punc_len;
} korea;

int readline(char *buf, int num);
korea getStringLength(const char str[]);
char *printString(char *str, int num);

int name_asc(const void *a, const void *b);
int name_desc(const void *a, const void *b);
int address_asc(const void *a, const void *b);
int address_desc(const void *a, const void *b);
int employee_asc(const void *a, const void *b);
int employee_desc(const void *a, const void *b);
int CEO_asc(const void *a, const void *b);
int CEO_desc(const void *a, const void *b);
int field_asc(const void *a, const void *b);
int field_desc(const void *a, const void *b);

int new_create();
int edit_company(int list_num, int success);
int delete_company(int num, int success);
int get_company(int num, int success);
int search_company(char *data, int success);
int sort_company(int size, char *set_order, int set_thing);
int get_list();

int main()
{
	char button[50];

	printf("기업관리 프로젝트\n\n");
	printf("입력받는 화면(n) 리스트 출력(l) 프로그램 종료(q)\n\n");
	printf("메인 화면 입력 : ");

	while(1) {
		scanf("%s", button);
		
		if((button[0] =='q')&&(strlen(button)==1))
			break;
		else if ((button[0] == 'n')&&(strlen(button)==1)) {
			printf("\n");
			new_create();
			printf("메인 화면 입력 : ");
			button[0] = '\0';
		} else if ((button[0] == 'l')&&(strlen(button)==1)) {
			get_list();
			printf("\n");
			printf("메인 화면 입력 : ");
			button[0] = '\0';
		} else {
			printf("메인 화면 재입력 : ");
			button[0] = '\0';
		}
	}

	return 0;
}

int readline(char *buf, int num)
{
    int i;

    for(i=0; i<num-1; i++) {
        read(0, buf+i, 1);
        if(*(buf+i) == '\n') break;
        if(buf[i] == '\r') continue;
    }
    buf[i] = 0;
    return i;
}

korea getStringLength(const char str[])
{
	korea this;

	this.kor_len = 0;
	this.eng_len = 0;
	this.blk_len = 0;
	this.punc_len = 0;
	
	for(int j=0;str[j];j++) {
		if(ispunct(str[j])!=0) {
			this.punc_len++;
			continue;
		} else if(isspace(str[j])!=0) {
			this.blk_len++;
			continue;
		} else if(str[j] & 0x80) {
			this.kor_len++;
		} else if(isalnum(str[j])!=0) {
			this.eng_len++;
		} else if(str[j] == '\0') {
			break;
		}
	}
	this.len = this.kor_len/3+this.eng_len+this.punc_len+this.blk_len;
	
	return this;
}

char *printString(char *str, int num)
{
	int blank = 0;

	korea get = getStringLength(str);
	char *dest = malloc(sizeof(char) * 30);
	char *first = malloc(sizeof(char) * 30);
	char *comma = "..";

	if(get.kor_len>0) {

		if(get.kor_len/2+get.eng_len+get.blk_len+get.punc_len>=num) {
			strncat(first, str, 27);
			korea check = getStringLength(first);
			
			strncat(dest, first, check.kor_len+(27-check.kor_len)/3*2);
			strcat(dest, comma);
			
			return dest;
		} else {
			blank = num-(get.kor_len/3*2+get.eng_len+get.blk_len+get.punc_len);
			char blank_n[30] = "                              ";
			strncat(str, blank_n, blank);
			return str;
		}
	} else {
		if(get.len>=num) {
			strncat(dest, str, num-2);
			strcat(dest, comma);
			return dest;
		} 
		return str;
	}
}

int name_asc(const void *a, const void *b) {
	struct Company *A = (struct Company *)a;
	struct Company *B = (struct Company *)b;
	return strcmp(A->name, B->name);
}

int name_desc(const void *a, const void *b) {
	struct Company *A = (struct Company *)a;
	struct Company *B = (struct Company *)b;
	return strcmp(B->name, A->name);
}

int address_asc(const void *a, const void *b) {
	struct Company *A = (struct Company *)a;
	struct Company *B = (struct Company *)b;
	return strcmp(A->address, B->address);
}

int address_desc(const void *a, const void *b) {
	struct Company *A = (struct Company *)a;
	struct Company *B = (struct Company *)b;
	return strcmp(B->address, A->address);
}

int employee_asc(const void *a, const void *b) {
	struct Company *A = (struct Company *)a;
	struct Company *B = (struct Company *)b;
	if(A->employee > B->employee) return 1;
	else if(A->employee < B->employee) return -1;
	else {
		return strcmp(A->name, B->name);
	}
}

int employee_desc(const void *a, const void *b) {
	struct Company *A = (struct Company *)a;
	struct Company *B = (struct Company *)b;
	if(A->employee < B->employee) return 1;
	else if(A->employee > B->employee) return -1;
	else {
		return strcmp(B->name, A->name);
	}
}

int CEO_asc(const void *a, const void *b) {
	struct Company *A = (struct Company *)a;
	struct Company *B = (struct Company *)b;
	return strcmp(A->CEO, B->CEO);
}

int CEO_desc(const void *a, const void *b) {
	struct Company *A = (struct Company *)a;
	struct Company *B = (struct Company *)b;
	return strcmp(B->CEO, A->CEO);
}

int field_asc(const void *a, const void *b) {
	struct Company *A = (struct Company *)a;
	struct Company *B = (struct Company *)b;
	return strcmp(A->field, B->field);
}

int field_desc(const void *a, const void *b) {
	struct Company *A = (struct Company *)a;
	struct Company *B = (struct Company *)b;
	return strcmp(B->field, A->field);
}

int new_create()
{	
	struct Company data;

	printf("기업을 입력해주세요\n");
	int fd, success = 0;
	char info[5][20] = {"company's name", "company's address", "company's employee", "company's CEO", "company's field"};
	
	if((fd=open("company.dat", O_RDWR | O_CREAT, 0644))==-1)
		printf("file error!\n");

	for(int i=0;i<lseek(fd, 0, SEEK_END)/772;i++) {
		lseek(fd,772*i, SEEK_SET);
		read(fd, &data, sizeof(data));

		if(data.employee == 0) {
			lseek(fd, 772*i, SEEK_SET);
			bzero(&data, sizeof(data));
	
			printf("%s\n",info[0]);
			readline(data.name, 128);

			printf("%s\n",info[1]);
			readline(data.address, 256);
	
			printf("%s\n",info[2]);
			scanf("%d", &data.employee);
	
			printf("%s\n",info[3]);
			readline(data.CEO, 128);
	
			printf("%s\n",info[4]);
			readline(data.field, 256);
	
			write(fd, &data, sizeof(data));
			success = 1;
			break;
		}
	}

	if(success == 0) {
		lseek(fd, 0, SEEK_END);
		bzero(&data, sizeof(data));
	
		printf("%s\n",info[0]);
		readline(data.name, 128);

		printf("%s\n",info[1]);
		readline(data.address, 256);
	
		printf("%s\n",info[2]);
		scanf("%d", &data.employee);
	
		printf("%s\n",info[3]);
		readline(data.CEO, 128);
	
		printf("%s\n",info[4]);
		readline(data.field, 256);
	
		write(fd, &data, sizeof(data));
	}

	close(fd);
	printf("\n");

	return 0;
}

int edit_company(int list_num, int success)
{
	printf("\nname edit(1) address edit(2) employee edit(3) CEO edit(4) field edit(5)\n");

	int fd, i, num, non_blank=0, edit_num=0;
	
	if((fd=open("company.dat", O_RDWR, 0644))==-1)
		printf("file error!\n");

	int size = lseek(fd,0,SEEK_END)/772;
	lseek(fd, 0, SEEK_SET);

	struct Company edit, sort[size], set[size];

	for(i=0;i<size;i++) {
		read(fd, &sort[i], sizeof(sort[i]));
		lseek(fd, 772*i, SEEK_SET);
		read(fd, &set[i], sizeof(set[i]));
	}

	if(success==1) {
		qsort(sort, size, sizeof(struct Company), name_asc); 
	} else if(success==2) {
		qsort(sort, size, sizeof(struct Company), address_asc); 	
	} else if(success==3) {
		qsort(sort, size, sizeof(struct Company), employee_asc); 
	} else if(success==4) {
		qsort(sort, size, sizeof(struct Company), CEO_asc); 
	} else if(success==5) {
		qsort(sort, size, sizeof(struct Company), field_asc); 
	} else if(success==6) {
		qsort(sort, size, sizeof(struct Company), name_desc); 
	} else if(success==7) {
		qsort(sort, size, sizeof(struct Company), address_desc); 	
	} else if(success==8) {
		qsort(sort, size, sizeof(struct Company), employee_desc); 
	} else if(success==9) {
		qsort(sort, size, sizeof(struct Company), CEO_desc); 
	} else if(success==10) {
		qsort(sort, size, sizeof(struct Company), field_desc);
	}

	lseek(fd, 0, SEEK_SET);

	for(i=0;i<size;i++) {	
		if(sort[i].employee == 0) {
			non_blank++;
			continue;
		}

		if(i+1-non_blank == list_num) {
			for(int j=0;j<size;j++){
				if(strstr(sort[i].name, set[j].name)&&(strlen(sort[i].name)==strlen(set[j].name))) {
					edit_num = j;
					break;
				}
			}
			break;
		}
	}

	bzero(&edit, sizeof(edit));
	
	printf("\n수정할 항목을 입력하세요 : ");
	scanf("%d", &num);

	char src[256];
	
	if(num!=3) {
		printf("\n수정 사항 입력 : ");
		scanf(" %[^\n]s", src);
	}

	if(num==1) {
		char *dest1 = edit.name;
		
		memcpy(dest1, src, sizeof(char)*strlen(src)+1);
		lseek(fd, 772*edit_num, SEEK_SET);
		write(fd, edit.name, sizeof(edit.name));
	} else if(num==2) {
		char *dest2 = edit.address;

		memcpy(dest2, src, sizeof(char)*strlen(src)+1);
		lseek(fd, 772*edit_num+128, SEEK_SET);
		write(fd, edit.address, sizeof(edit.address));
	} else if(num==3) {
		printf("\n수정 사항 입력 : " );
		scanf("%d", &edit.employee);

		lseek(fd, 772*edit_num+384, SEEK_SET);
		write(fd, &edit.employee, sizeof(edit.employee));
	} else if(num==4) {
		char *dest4 = edit.CEO;
		
		memcpy(dest4, src, sizeof(char)*strlen(src)+1);
		lseek(fd, 772*edit_num+388, SEEK_SET);
		write(fd, edit.CEO, sizeof(edit.CEO));
	} else if(num==5) {
		char *dest5 = edit.field;
		
		memcpy(dest5, src, sizeof(char)*strlen(src)+1);
		lseek(fd, 772*edit_num+516, SEEK_SET);
		write(fd, edit.field, sizeof(edit.field));
	}

	close(fd);
	return 0;
}

int delete_company(int num, int success) {
	int fd, i, non_blank=0;
	
	if((fd=open("company.dat", O_RDWR, 0644))==-1)
		printf("file error!\n");
		
	int size = lseek(fd,0,SEEK_END)/772;

	struct Company delete[size], some[size];

	lseek(fd,0,SEEK_SET);

	for(i=0;i<size;i++) {
		read(fd, &delete[i], sizeof(delete[i]));
		lseek(fd, 772*i, SEEK_SET);
		read(fd, &some[i], sizeof(some[i]));
	}

	if(success==1) {
		qsort(delete, size, sizeof(struct Company), name_asc); 
	} else if(success==2) {
		qsort(delete, size, sizeof(struct Company), address_asc); 	
	} else if(success==3) {
		qsort(delete, size, sizeof(struct Company), employee_asc); 
	} else if(success==4) {
		qsort(delete, size, sizeof(struct Company), CEO_asc); 
	} else if(success==5) {
		qsort(delete, size, sizeof(struct Company), field_asc); 
	} else if(success==6) {
		qsort(delete, size, sizeof(struct Company), name_desc); 
	} else if(success==7) {
		qsort(delete, size, sizeof(struct Company), address_desc); 	
	} else if(success==8) {
		qsort(delete, size, sizeof(struct Company), employee_desc); 
	} else if(success==9) {
		qsort(delete, size, sizeof(struct Company), CEO_desc); 
	} else if(success==10) {
		qsort(delete, size, sizeof(struct Company), field_desc);
	}

	lseek(fd, 0, SEEK_SET);

	for(i=0;i<size;i++) {	
		if(delete[i].employee == 0) {
			non_blank++;
			continue;
		}

		if(i+1-non_blank == num) {
			for(int j=0;j<size;j++){
				if(strstr(delete[i].name, some[j].name)&&(strlen(delete[i].name)==strlen(some[j].name))) {
					lseek(fd, 772*j, SEEK_SET);
					memset(&delete[i], 0, sizeof(delete[i]));
					write(fd, &delete[i], sizeof(delete[i]));
					break;
				}
			}
			break;
		}
	}

	close(fd);
	return 0;
}

int get_company(int num, int success)
{
	char ch[50];
	int fd, i, non_blank=0;

	if((fd=open("company.dat", O_RDONLY, 0644))==-1)
		printf("file error!\n");
	
	int size = lseek(fd, 0, SEEK_END)/772;

	struct Company info[size];

	lseek(fd,0,SEEK_SET);

	for(i=0;i<size;i++)
		read(fd, &info[i], sizeof(info[i]));


	if(success==1) {
		qsort(info, size, sizeof(struct Company), name_asc); 
	} else if(success==2) {
		qsort(info, size, sizeof(struct Company), address_asc); 	
	} else if(success==3) {
		qsort(info, size, sizeof(struct Company), employee_asc); 
	} else if(success==4) {
		qsort(info, size, sizeof(struct Company), CEO_asc); 
	} else if(success==5) {
		qsort(info, size, sizeof(struct Company), field_asc); 
	} else if(success==6) {
		qsort(info, size, sizeof(struct Company), name_desc); 
	} else if(success==7) {
		qsort(info, size, sizeof(struct Company), address_desc); 	
	} else if(success==8) {
		qsort(info, size, sizeof(struct Company), employee_desc); 
	} else if(success==9) {
		qsort(info, size, sizeof(struct Company), CEO_desc); 
	} else if(success==10) {
		qsort(info, size, sizeof(struct Company), field_desc);
	}
	
	lseek(fd, 0, SEEK_SET);

	for(i=0;i<size;i++) {	
		if(info[i].employee == 0) {
			non_blank++;
			continue;
		}

		if(i+1-non_blank == num) {
			printf("\n%-8s : %s\n", "name", info[i].name);
			printf("%-8s : %s\n", "address", info[i].address);
			printf("%-8s : %d\n", "employee", info[i].employee);
			printf("%-8s : %s\n", "CEO", info[i].CEO);
			printf("%-8s : %s\n", "field", info[i].field);
			break;
		}
	}

	printf("\n수정하기(e)\n");
	printf("삭제하기(d)\n");
	printf("나가기(q)\n\n");

	printf("회사 정보 화면 입력 : ");

	while(1) {
		scanf("%s", ch);
		if((ch[0] == 'e')&&(strlen(ch)==1)) {
			edit_company(num, success);
			break;
		} else if((ch[0]=='d')&&(strlen(ch)==1)) {
			delete_company(num, success);
			break;
		} else if((ch[0]=='q')&&(strlen(ch)==1)) {
			break;
		} else 
			printf("\n회사 정보 화면 재입력 : ");
	}

	close(fd);
	return 0;
}

int search_company(char *data, int success)
{
	int fd, size, i, find=0;

	if((fd=open("company.dat", O_RDONLY, 0644))==-1)
		printf("file error!\n");
	
	size = lseek(fd, 0, SEEK_END);

	struct Company search_list[size/772];

	lseek(fd, 0, SEEK_SET);

	for(i=0;i<size/772;i++) {
		bzero(&search_list[i], sizeof(search_list[i]));
		read(fd, &search_list[i], sizeof(search_list[i]));

		if(strstr(data, search_list[i].name)&&(strlen(data)==strlen(search_list[i].name))) {
			find = 1;
			break;
		}
	}

	if(find==1)
		get_company(i+1, success);
	else 
		printf("\n찾지 못했습니다.\n");

	return 0;
}

int sort_company(int size, char *set_order, int set_thing)
{
	struct Company sort_list[size];
	int fd, i, thing, success = 0, j=10, len=0, non_blank=0, dest_true = 0;
	char order[50], n[256];
	char *dest;

	if((fd=open("company.dat", O_RDONLY, 0644))==-1)
		printf("file error!\n");
	
	for(i=0;i<size;i++)
		read(fd, &sort_list[i], sizeof(sort_list[i]));

	while(1) {
		if(set_thing == 0) {
			printf("\n오름차순(a) 내림차순(d) 원본으로(b) : ");
			scanf("%s", order);
			
			if(!((order[0]=='b')&&(strlen(order)==1))) {
				printf("name(1) address(2) employee(3) CEO(4) field(5) : ");
				scanf("%d", &thing);
			}
		} else {
			strcpy(order, set_order);
			thing = set_thing;
		}
		
		if(j>thing)
			len++;

		if((order[0]=='a')&&(strlen(order)==1)) {
			if((thing==1)&&(len==1)) {
				qsort(sort_list, size, sizeof(struct Company), name_asc); 
				success=1;
				break;
			} else if((thing==2)&&(len==1)) {
				qsort(sort_list, size, sizeof(struct Company), address_asc); 
				success=2;
				break;
			} else if((thing==3)&&(len==1)) {
				qsort(sort_list, size, sizeof(struct Company), employee_asc); 
				success=3;
				break;
			} else if((thing==4)&&(len==1)) {
				qsort(sort_list, size, sizeof(struct Company), CEO_asc); 
				success=4;
				break;
			} else if((thing==5)&&(len==1)) {
				qsort(sort_list, size, sizeof(struct Company), field_asc); 
				success=5;
				break;
			}
		} else if((order[0]=='d')&&(strlen(order)==1)) {
			if((thing==1)&&(len==1)) {
				qsort(sort_list, size, sizeof(struct Company), name_desc); 
				success=6;
				break;
			} else if((thing==2)&&(len==1)) {
				qsort(sort_list, size, sizeof(struct Company), address_desc); 
				success=7;
				break;
			} else if((thing==3)&&(len==1)) {
				qsort(sort_list, size, sizeof(struct Company), employee_desc); 
				success=8;
				break;
			} else if((thing==4)&&(len==1)) {
				qsort(sort_list, size, sizeof(struct Company), CEO_desc); 
				success=9;
				break;
			} else if((thing==5)&&(len==1)) {
				qsort(sort_list, size, sizeof(struct Company), field_desc); 
				success=10;
				break;
			}
		} else if((order[0]=='b')&&(strlen(order)==1)) {
			get_list();
			break;
		} else {
			printf("\n");
			continue;
		}
	}
	
	if(success!=0) {
		lseek(fd, 0, SEEK_SET);

		printf("\n---------------------------------------------------------------------------------------------------------\n");
		printf("|%-3s |%-20s |%-30s |%-10s |%-10s |%-20s|\n", "Num", "Name", "Address", "Employee", "CEO", "Field");
		printf("---------------------------------------------------------------------------------------------------------\n");

		for(i=0;i<size;i++) {	
			if(sort_list[i].employee == 0) {
				non_blank++;
				continue;
			}

			printf("|%-3d |%-20s |%-30s |%-10d |%-10s |%-20s|\n",i+1-non_blank, printString(sort_list[i].name, 20), printString(sort_list[i].address, 30), sort_list[i].employee, printString(sort_list[i].CEO, 10), printString(sort_list[i].field, 20));

			printf("---------------------------------------------------------------------------------------------------------\n");
		}

		printf("\n회사 정보 보기(숫자)\n");
		printf("회사 이름 검색(해당 회사 이름)\n");
		printf("이름 순으로 정렬(s)\n");
		printf("나가기(q)\n\n");
		
		printf("리스트 화면 입력 : ");

		while(1) {
			scanf("%s", n);

			if(isdigit(n[0])==0) {
				if((n[0]=='q')&&(strlen(n)==1)) {
					break;
				} else if((n[0]=='s')&&(strlen(n)==1)) {
					sort_company(size, "?", 0);
				} else {
					search_company(n, success);
					sort_company(size, order, thing);
					break;
				}
			} else {
				for(int i=0;i<strlen(n);i++) {
					if(isdigit(n[i]) == 0) {
						dest_true = 1;
						break;
					}
				}
				if(dest_true == 0) {
					dest = n;
					get_company(atoi(dest), success);
					sort_company(size, order, thing);
					break;
				} else 
					printf("리스트 화면 재입력 : ");
			}
		}
	}

	return 0;
}

int get_list()
{
	int fd, i, non_blank=0, dest_true = 0;
	char n[256];
	char *dest;

	if((fd=open("company.dat", O_RDONLY, 0644))==-1)
		printf("file error!\n");
	
	int size = lseek(fd, 0, SEEK_END);

	struct Company read_list[size/772];

	lseek(fd, 0, SEEK_SET);

	printf("\n---------------------------------------------------------------------------------------------------------\n");
	printf("|%-3s |%-20s |%-30s |%-10s |%-10s |%-20s|\n", "Num", "Name", "Address", "Employee", "CEO", "Field");
	printf("---------------------------------------------------------------------------------------------------------\n");

	for(i=0;i<size/772;i++) {
		bzero(&read_list[i], sizeof(read_list[i]));
		read(fd, &read_list[i], sizeof(read_list[i]));
		
		if(read_list[i].employee == 0) {
			non_blank++;
			continue;
		} 

		printf("|%-3d |%-20s |%-30s |%-10d |%-10s |%-20s|\n",i+1-non_blank, printString(read_list[i].name, 20), printString(read_list[i].address, 30), read_list[i].employee, printString(read_list[i].CEO, 10), printString(read_list[i].field, 20));

		printf("---------------------------------------------------------------------------------------------------------\n");
	}
	
	printf("\n회사 정보 보기(숫자)\n");
	printf("회사 이름 검색(해당 회사 이름)\n");
	printf("이름 순으로 정렬(s)\n");
	printf("나가기(q)\n\n");
	
	printf("리스트 화면 입력 : ");

	while(1) {
		scanf("%s", n);

		if(isdigit(n[0])==0) {
			if((n[0]=='q')&&(strlen(n)==1)) {
				break;
			} else if((n[0]=='s')&&(strlen(n)==1)) {
				sort_company(size/772, "?", 0);
				break;
			} else {
				search_company(n, 0);
				get_list();
				break;
			}
		} else {
			for(i=0;i<strlen(n);i++) {
				if(isdigit(n[i]) == 0) {
					dest_true = 1;
					break;
				}
			}

			if(dest_true == 0) {
				dest = n;
				get_company(atoi(dest), 0);
				get_list();
				break;
			} else 
				printf("리스트 화면 재입력 : ");
		}
	}

	close(fd);
	return 0;
}
