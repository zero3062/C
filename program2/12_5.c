#include <stdio.h>
#include <stdlib.h> /*srand, rand 함수가 정의된 헤더 파일*/
#include <time.h> /*time함수가 정의된 헤더 파일*/

int main()
{
	int i;

	/*seed에 항상 바뀌는 time 함수르 두어 초기화*/
	srand((unsigned)time(NULL));

	for(i=0;i<10;i++) {
		/*난수를 생성하고 이를 10으로 나눈 나머지를 출력*/
		printf("%d ", rand()%100);
	}
	printf("\n");
}
