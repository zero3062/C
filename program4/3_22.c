#include <stdio.h>
int main()
{
	int i;

	for(i=1; i<=30; i++){
		/*i를 5로 나눈 나머지가 0이 아니면*/
		if(i%5)
			continue; /*for문의 다음 반복을 실행*/
		printf("%d", i);
	}
	printf("\n");
}
