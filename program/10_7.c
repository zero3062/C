#include <stdio.h>
#include <string.h>	/* memmove 함수가 정의된 헤더 파일 */

main()
{
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	/* alphabet 7번째 영역부터 19바이트 크기의 내용을 alphabet 첫 부분에 
	   복사하여 덮어쓰기가 되고, 만약 세 번째 인수르 19가 아닌 20ㅇ로 설정하면
	   NULL('\0') 문자까지 복사되어 다음과 같이 NULL 문자까지만 출력됨 */
	memmove(alphabet, alphabet+7, 19);
	printf("%s\n", alphabet);
}
