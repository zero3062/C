#include <stdio.h>

main()
{
	int ch, numalpha=0;

	/* 입력이 종료될 때까지 반복 */
	while((ch=getchar()) != EOF) {
		/* ch가 영문자면 */
		if((ch>='A'&&ch<='Z') || (ch>='a'&&ch<='z'))
			numalpha++;
	}
	printf("alphabet : %d\n", numalpha);
}
