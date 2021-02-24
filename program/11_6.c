#include <stdio.h>

main()
{
	FILE *ifp, *ofp;
	int ch;

	/* source 파일을 읽기 전용으로 열기 */
	ifp = fopen("source", "r");
	/* result 파일을 쓰기 전용으로 열기 */
	ofp = fopen("result", "w");

	/* ifp 파일로부터 한 문자 읽기 */
	while((ch=fgetc(ifp)) != EOF)
		/* 읽기 문자 ofp 파일에 쓰기 */
		fputc(ch, ofp);

	/* 파일 닫기 */
	fclose(ifp);
	fclose(ofp);
}
