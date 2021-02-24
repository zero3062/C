#include <stdio.h>
#define MAX 1024

int main()
{
	FILE *fp;
	char buffer[MAX];
	int ch, chk=0;

	/*source파일을 읽기 전용으로 열기*/
	fp = fopen("source", "r");

	/*fp파일의 끝까지 반복*/
	while((ch=fgetc(fp))!=EOF) {
		/*읽은 문자가 'L'이면*/
		if(ch=='L') {
			chk=1;
			break;
		}
	}

	/*방금전에 읽은 문자가 'L'이면 */
	if(chk==1){
		/*fp파일로 방금전에 읽은 'L'을 되돌림*/
		ungetc(ch,fp);
		/*fp파일의 행 끝까지의 문자열을 읽어 buffer에 저장*/
		fgets(buffer, MAX, fp);
		printf("%s\n", buffer);
	}else {
		printf("NotFound\n");
	}
	fclose(fp);
}
