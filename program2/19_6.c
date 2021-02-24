#include <stdio.h>
#include <stdlib.h>
#define NDEBUG /*NDEBUG를 정의하면 assert 호출 문자을 실행하지 않음*/
#include <assert.h>

int main()
{
	FILE *fp;

	fp=fopen("yesdata", "r");
	assert(fp); /*실행되지 않음*/
	printf("yesdata exit\n");
	fclose(fp);

	fp=fopen("nodata", "r");
	assert(fp); /*실행되지 않음*/
	printf("nodata exit\n");
	fclose(fp);

	exit(0);
}
