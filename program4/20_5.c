#include <stdio.h>
#include <unistd.h> /*getopt 함수를 정의하는 헤더 파일*/
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int opt;

	while ((opt = getopt(argc, argv, "lf:ai")) != -1) {
		switch(opt){
			case 'l':
			case 'a':
			case 'i':
				printf("option: %c\n", opt);
				break;
			case 'f':
				printf("option %c's argument :%s\n", opt, optarg);
				break;
			case '?':
				printf("unknow option : %c\n", optind);
		}
	}
	/*처리되지 않은 인수들을 출력, optind에 다음에 처리해야 할 인수의 argv 첨자 저장*/
	for(; optind<argc; optind++)
		printf("argument : %s\n", argv[optind]);
	exit(0);
}

