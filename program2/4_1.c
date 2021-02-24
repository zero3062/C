#include <stdio.h>
#define MAX 20 /* 배열의 크기를 나타내는 메크로로 MAX는 기호 상수로 20을 의미 */

int main()
{
	int i, num;
	int arr[MAX]; /* 배열 변수 선언: MAX 크기의 int형 배열을 선언한다. */
	
	printf("Input number of data ==> ");
	scanf("%d", &num); /* 데이터의 수 입력: int형 데이터를 입력받아 arr[i]에 저장한다. */

	/* 표준 입력 장치(키보드)를 통해 num개의 데이터 입력 */
	for(i=0; i<num; i++) {
		printf("%dth number ==> ", i+1);
		scanf("%d", &arr[i]);
	}

	/* 입력받은 데이터를 출력 */
	printf("\nInput data\n");
	for(i=0; i<num; i++) 
		printf("%d ", arr[i]);

	/* arr에 저장된 데이터를 끝(num-1)에서부터 앞(0)으로, 즉 역순으로 출력한다. */
	printf("\nReverse data\n");
	for(i=num-1; i>=0; i--)
		printf("%d ", arr[i]);
	printf("\n");
}
