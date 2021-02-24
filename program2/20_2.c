#include <stdio.h>
#include <stdlib.h> /*atoi함수를 정의하는 헤더 파일*/

int max(int num1, int num2);

int main(int argc, char *argv[])
{
	/*인수를 잘못 주어 실행시켰을 때*/
	if(argc!=3) {
		printf("Usage : a.out number1 number2\n");
		exit(1);
	}
	/*atoi는 정수 형태의 문자열을 정수로 변환하는 함수*/
	printf("max number : %d\n", max(atoi(argv[1]), atoi(argv[2])));
	exit(0);
}

int max(int num1, int num2)
{
	if(num1>num2)
		return num1;
	else
		return num2;
}
