#include <stdio.h>

main()
{
	int ch;

	while((ch=getchar()) != EOF) {
		/* ch가 소문자면 */
		if(ch>='a'&&ch<='z')
			/* 대문자로 변환하는 부분인데 만약 ch에 'c'가 저장되어 있다고 가정하면
			   'c'-'a'는 2가 되고 2+'A'는 'C'가 되어 대문자로 변환 */
			ch = ch-'a'+'A';
		putchar(ch);
	}
	putchar('\n');
}
