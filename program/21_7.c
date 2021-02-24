#include <stdio.h>

main()
{
	/* FOPEN_MAX는 하나의 프로그램에서 동시에 열 수 있는 파일의 수를 의미 */
	printf("FOPEN_MAX : %d\n", FOPEN_MAX);
	exit(0);
}
