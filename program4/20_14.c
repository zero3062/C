#include <stdio.h>
#include <stdlib.h> /* setenv, getenv 함수를 정의하는 헤더 파일*/

int main()
{
	char *value;

	/*overwrite가 0이므로 이미 HOME이 존재하면 변경하지 않음*/
	setenv("HOME", "/home/jkim/book/linux", 0);
	value = getenv("HOME");
	printf("[setenv overwrite : 0] HOME : %s\n", value);

	/*overwrite가 1이므로 이미 HOME이 존재해도 값을 변경*/
	setenv("HOME", "/home/jkim/book/linux", 1);
	value = getenv("HOME");
	printf("[setenv overwrite : 1] HOME : %s\n", value);

	exit(0);
}
