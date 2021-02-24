#include <stdio.h>

int main()
{
	char ch;

	printf("Input character ==> ");
	scanf("%c", &ch);
	if((ch>='a')&&(ch<='z'))
		ch = ch-'a'+'A';
	printf("%c\n", ch);
}
