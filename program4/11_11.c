#include <stdio.h>

int main()
{
	FILE *fp;

	/*source 파일을 읽기 전용으로 열기 */
	fp = fopen("source", "r");

	/*fp 파일로부터 한 문자를 읽어 ch에 저장*/
	ch = fgetc(fp);
	ch = fgetc(fp);
	/*fp파일에 대한 읽기/쓰기 포인터를 출력*/
	printf("%ld\n", ftell(fp));
	
	/*fp파일에 대한 읽기/쓰기 포인터를 처음으로 되돌려 읽기/쓰기 포인터 값은 0이 됨*/
	rewind(fp);
	printf("%ld\n", ftell(fp));

	fclose(fp);
}
