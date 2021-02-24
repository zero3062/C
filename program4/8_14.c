#include <stdio.h>
#include <string.h> /* strpbrk 함수가 정의된 헤더파일*/

int main()
{
	char *ptr;

	/*"seoulKorea"에서 "Ka"의 문자들 중 일치하는 첫 번재 문자는 'K'므로 
	  이 문자에 대한 포인터를 반환*/
	ptr = strpbrk("seoulKorea", "Ka");
	printf("%s\n", ptr);
}
