#include <stdio.h>
#include <stdlib.h> /*calloc함수가 정의된 헤더 파일*/
#include <string.h> /*memcpy함수가 정의된 헤더 파일*/

int main()
{
	int *ptr;
	int arr[5] = {1, 2, 3, 4, 5};
	int i;

	/*innt 형 요소 5개로 이루어진 배열을 동적으로 할당하고 ptr이 가리킴*/
	if((ptr=(int *)calloc(5, sizeof(int)))==NULL)
		exit(1);

	/*arr이 가리키는 영역의 5*sizeof(int) 바이트를 ptr이 가리키는 영역으로 복사*/
	memcpy(ptr, arr, 5*sizeof(int));

	/*할당된 메모리 영역에 저장된 값 출력*/
	for(i=0;i<5;i++)
		printf("%d ", ptr[i]);
	printf("\n");
}
