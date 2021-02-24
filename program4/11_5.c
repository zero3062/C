#include <stdio.h> /*fopen, fclose 함수가 정의된 헤더 파일*/

int main()
{
	FILE *fp; /*FILE형은 stdio.h헤더 파일에 정의되어 있음*/

	/*jkim파일을 읽기 전용으로 열기
	  반환되는 값은 jkim파일에 대한 파일 포인터로 fp에 저장*/
	fp = fopen("jkim", "r");
	/*fp파일을 닫기, fp는 fopen에 의해 반환된 값*/
	fclose(fp);
}
