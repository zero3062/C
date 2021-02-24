#include <stdio.h>
main()
{
	int arr[5] = {10, 20, 30, 40, 50};
	int *ptr; /* 포인터 변수 ptr 선언 */
	int i;

	/* ptr을 이용해 arr의 내용 출력, ptr++는 ptr이 가리키는 배열 요소의 다음 요소 */
	for (ptr=arr, i=0; i<5; i++)
		printf("%d\n", *ptr++);
}
