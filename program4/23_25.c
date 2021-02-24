#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *str=0;
	int i=1;
	printf("Running %s with system\n", argv[1]);
	/*명령라인의 인수를 연결해서 str에 저장*/
	while(argc > i) {
		strcat(str, argv[i++]);
		strcat(str, "");
	}
	/*system을 이용해 str에 저장된 명령어 실행*/
	system(str);
	printf("Done\n");
	exit(0);
}
