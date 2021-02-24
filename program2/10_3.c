#include <stdio.h>
#include <stdlib.h> /*calloc, realloc 함수가 정의된 헤더 파일*/

int main()
{
	int *ptr;
	int arr[5] = {1, 2, 3, 4, 5};
	int i;

	/*int형 요소 5개로 이루어진 배열을 동적으로 할당하고 ptr이 가리킴*/
	if((ptr=(int *)calloc(5, sizeof(int)))==NULL)
		exit(1);

	/*할당된 메모리 영역에 arr값 저장*/
	for(i=0;i<5;i++)
		ptr[i]=arr[i];

	/*ptr이 가리키는 메모리 영역의 크기를 sizeof(int)*10으로 변경하고
	  이 영역에 대한 포인터를 반환하여 ptr이 이 영역을 가리킴*/
	if((ptr=(int *)realloc(ptr, sizeof(int)*10))==NULL)
		exit(1);

	/*추가된 메모리 영역에 arr 값 저장*/
	for(i=5;i<10;i++)
		ptr[i]=arr[i];

	/*할당된 메모리 영역에 저장된 값 출력*/
	for(i=0;i<10;i++)
		printf("%d ", ptr[i]);
	printf("\n");

	/*사용이 끝난 메모리 영역 해제*/
	free(ptr);
}
