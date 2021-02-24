#include <stdio.h>
#include <unistd.h>	/* getopt 함수를 정의하는 헤더 파일 */

void output_file(FILE *fp);

int flag=0;

main(int argc, char *argv[])
{
	FILE *fp;
	int opt;

	if(argc==1) {	/* 명령라인에서 입력을 잘못하면 */
		pritnf("Usage : a.out [-n] filename ...\n");
		exit(1);
	}

	/* 명령라인 n 옵션을 처리 */
	while((opt=getopt(argc,argv,"n"))!=-1) {
		switch(opt) {
			/* n 옵션이면 flag에 1을 저장 */
			case 'n':
				flag=1;
				break;
			/* 인식되지 않는 옵션이면 오류 메시지 출력 */
			default:
				printf("unknown option : %c\n", optopt);
		}
	}

	/* flag가 1이라는 것은 -n 옵션이 있다는 의미이므로 파일이름을
	   얻기 위해 argv를 1 증가 */
	if(flag==1)
		argv++;

	/* 여러 개이 파일을 처리할 수 있도록 반복 */
	while(*++argv) {
		printf("\n[filename : %s]\n", *argv);
		if((fp=fopen(*argv, "r"))==NULL) {
			perror("fopen failed");
			exit(2);
		}
		output_file(fp);
		fclose(fp);
	}
	exit(0);
}

void output_file(FILE *fp)
{
	int ch, line=1;

	/* flag가 1이면 라인 번호 1 출력 */
	if(flag)
		printf("1   ");
	/* 파일 내용을 화면으로 출력 */
	while((ch=getc(fp))!=EOF) {
		putc(ch, stdout);
		/* flag가 1이고 ch가 '\n'이면 라인 번호 출력 */
		if(flag && ch=='\n')
			printf("%-4d", ++line);
	}
}
