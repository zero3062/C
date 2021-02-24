#include <stdio.h>
#include <assert.h> /*assert함수를 정의하는 헤더 파일*/
#include <stdlib.h>

int main()
{
	FILE *fp;

	fp=fopen("yesdata", "r");
	/*fp가 참이므로 아무 일도 하지 않고 다음 문장을 실행한다*/
	assert(fp);
	printf("yesdata exist\n");
	fclose(fp); /*fp닫음*/

	fp=fopen("nodata", "r"); /*nodata없으므로 NULL반환*/
	assert(fp); /*fp가 거짓으므로 오류 메시지 출력, 코어 덤프하고 종료*/
	/*이후 문장 실행되지 않음*/
	printf("nodata exist\n");
	fclose(fp);

	exit(0);
}
