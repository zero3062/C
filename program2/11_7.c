#include <stdio.h>

int main()
{
	FILE *fp;
	int i;
	float j;
	char *str;

	/*data 파일을 쓰기 전용으로 열기. 반환되는 값은 data 파일에 대한 포인터*/
	fp=fopen("data", "w");
	/*fp 파일에 123, 12.345, "Hello"를 서식화하여 쓰기*/
	fprintf(fp, "%d %g %s\n", 123, 12.345, "Hello");
	fclose(fp);

	/*data파일을 읽기 전용으로 열기*/
	fp=fopen("data", "r");
	/*fp 파일로부터 데이터를 서식화하여 읽어 i, j, str에 저장*/
	fscanf(fp, "%d%g%s", &i, &j, str);
	printf("%d %g %s\n", i, j, str);
	fclose(fp);
}
