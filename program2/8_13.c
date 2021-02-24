#include <stdio.h>
#include <string.h> /* strspn 함수가 정의된 헤더 파일 */

int main()
{
	int n;

	/* "seoulKorea"에서 "elmnopsu"의 문자들로만 이루어진 처음 문자열인 "seoul"
	   문자열의 길이인 5를 반환 */
	n = strspn("seoulKorea", "elmnopsu");
	printf("%d\n", n);
}
