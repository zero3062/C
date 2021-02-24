#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *read_fp;
	char buffer[256];

	/*argv[1] 프로세스를 실행하고 읽기용 파이프를 생성, read_fp는 파이프를 가리킴*/
	if((read_fp = popen(argv[1], "r"))==NULL){
		perror("popen failed");
		exit(1);
	}

	/*read_fp 파이프로부터 데이터를 입력받아 출력*/
	while(fgets(buffer, sizeof(buffer), read_fp)) {
		fputs(buffer, stdout);
	}

	/*read_fp 파이프를 닫음*/
	pclose(read_fp);
	exit(0);
}
