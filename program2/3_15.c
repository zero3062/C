#include <stdio.h>
int main()
{
	int ch;

	printf("Input character ==> ");
	/* 키보드로 하나의 문자를 입력 */
	ch = getchar();

	/* ch에 저장된 내용이 영문자면 실행한다. */
	if ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		printf("alphabet character\n");
	/* ch에 저장된 내용이 영문자가 아니고 수치 문자면 실행한다. */
	else if (ch>='0'&&ch<='9')
		printf("numeric character\n");
	/* ch에 저장된 내용이 영문자도 아니고 수치 문자도 아니면 실행한다. */
	else
		printf("others\n");
}
