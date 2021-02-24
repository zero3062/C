#include <stdio.h> /*sprintf, sscanf, printf 함수가 정의된 헤더 파일*/
#define MAX 100

int main()
{
	int i=123;
	float j=23.456;
	char buffer1[MAX], buffer2[MAX];

	/*i와 j를 buffer1과 buffer2에 저장*/
	sprintf(buffer1, "%d", i);
	sprintf(buffer2, "%.3f", j);

	/*buffer1에 저장된 데이터를 8진수 형태로 읽어 i에 저장*/
	sscanf(buffer1, "%o", &i);
	printf("%d\n", i);

	/*buffer2에 저장된 데이터를 지수 형태로 읽어 j에 저장*/
	sscanf(buffer2, "%e", &j);
	printf("%e\n", j);
}
