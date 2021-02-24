#include <stdio.h>
int main()
{
	char *str;

	str = "Hello"; /* char형 포인터 변수에 문자열 저장 */
	for(; *str; str++)
		printf("%s\n", str);
}
