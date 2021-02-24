#include <stdio.h>
main()
{
	int ch, numl=0, nums=0;
	/* 하나의 문자를 키보드로 입력받아 ch에 저장하고, ch의 내용이 EOF가 아니면
	   실행하고 EOF이면 while문을 벗어난다. 여기서 EOF는 End Of File로 
	   파일의 끝을 의미한다. */
	while ((ch=getchar()) != EOF) {
		/* ch가 'A'보다 크거나 같고 'Z'보다 작거나 같으면, 즉 ch가 대문자면 */
		if((ch>='A') && (ch<='Z'))
			numl++;
		/* ch가 'a' 보다 크거나 같고 'z'보다 작거나 같으면, 즉 ch가 소문자면 */
		else if((ch>='a') && (ch<='z'))
			nums++;
	}
	printf("%d %d\n", numl, nums);
}
