#include <stdio.h>
#include <string.h> /*strerror함수를 정의하는 헤더 파일*/
#include <stdlib.h>
#include <errno.h>

int main()
{
	FILE *fp;

	/*fopen함수 호출에 실패하면 NULL이 반환*/
	if((fp=fopen("nodata", "r")) == NULL) {
		/*errno를 설명하는 문자열을 표준 오류인 모니터로 출력*/
		fprintf(stderr, "ERROR: %s\n", strerror(errno));
		exit(1);
	}
	exit(0);
}
