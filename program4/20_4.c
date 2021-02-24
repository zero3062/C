#include <stdio.h>
#include <unistd.h> /* getopt 함수를 정의하는 헤더 파일*/
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int opt;
	/*명령라인의 l, f, a, i 옵션을 처리*/
	while((opt=getopt(argc, argv, "lf:ai")) != -1) {
		switch(opt) {
			/*l, a, i 옵션이면 옵션을 출력*/
			case '1':
			case 'a':
			case 'i':
				printf("option : %c\n", opt);
				break;
			/*f옵션이면 옵션과 인수를 출력*/
			case 'f':
				printf("option %c's argument : %s\n", opt, optarg);
				break;
			/*인색되지 않는 옵션 출력*/
			default:
				printf("unknown option : %c\n", optopt);
		}
	}
	exit(0);
}
