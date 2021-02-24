#include <stdio.h>
#include <stdlib.h> /* atoi 함수가 정의된 헤더 파일 */

main()
{
	int i;

	/* 10진 정수 형태의 문자열 "23"과 "567"을 정수 23과 567로 변환 */
	i = atoi("23")+atoi("567");
	printf("%d\n", i);
}
