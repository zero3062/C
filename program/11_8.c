#include <stdio.h>
#define MAX 1024

main()
{
	FILE *ifp, *ofp;
	char buffer[MAX];
	int num;
	/* source 파일을 읽기 전용으로 열기 */
	ifp = fopen("source", "r");
	/* result 파일을 쓰기 전용으로 열기 */
	ofp = fopen("result", "w");

	/* ifp 파일로부터 1바이트 크기의 MAX개 데이터를 입력받아 buffer에 저장.
	   반환되는 값은 실제 얽힌 데이터의 수 */
	num = fread(buffer, 1, MAX, ifp);
	/* buffer에서 1바이트 크기의 num개의 데이터를 ofp 파일에 출력 */
	fwrite(buffer, 1, num, ofp);

	/* 파일 닫기 */
	fclose(ifp);
	fclose(ofp);
}
