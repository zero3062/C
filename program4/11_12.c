#include <stdio.h>

int main()
{
	FILE *fp;
	int ch;

	/*alphabet파일을 읽기 전용으로 열기*/
	fp = fopen("alphabet", "r");
	/*fp파일에 대한 ㅇ릭기/쓰기 포인터를 시작 위치에서 우측으로 10칸 이동 */
	fseek(fp, 10, SEEK_SET);

	/*fp파일로부터 한 문자씩 읽어서 출력 */
	while((ch=fgetc(fp)) != EOF) {
		putchar(ch);
	}
	fclose(fp);
}
