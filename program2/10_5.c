#include <stdio.h>
#include <stdlib.h> /*malloc함수가 정의된 헤더 파일*/
#include <string.h> /*memset함수가 정의된 헤더 파일*/

int main()
{
	int *ptr;

	/*10바이트 크기의 메모리를 할당하고 ptr이 가리킴*/
	if((ptr=(int *)malloc(10))==NULL)
		exit(1);

	/*ptr이 가리키는 메모리 영역의 9바이트를 'a'로 초기화*/
	memset(ptr, 'a', 9);
	ptr[9]='\0';

	printf("%ls\n", ptr);

	/*메모리 영역 해제*/
	free(ptr);
}
