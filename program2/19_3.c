#include <stdio.h>
#include <stdlib.h>
#include <math.h> /*sqrt 함수를 정의하는 헤더 파일*/
#include <errno.h> /*errno 변수를 선언하는 헤더 파일*/

int main()
{
	double y;

	errno = 0; /*errno를 0으로 초기화*/
	y=sqrt(-1); /*sqrt 함수의 인수로 음수 값이 올 수 없으므로 호출 오류 발생*/

	/*errno가 0이 아니라는 것은 오류가 발생했음을 의미*/
	if(errno != 0) {
		printf("errno =%d\n", errno); /*errno에 저장된 오류 번호 출력*/
		exit(1);
	}
	exit(0);
}
