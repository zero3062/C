#include <stdio.h>
#include <search.h>	/* lfind 함수가 정의된 헤더 파일 */
#include <string.h> /* strcmp 함수가 정의된 헤더 파일 */

#define TABLESIZE 10 /* 테이블 크기 */
#define ELEMENTSIZE 15 /* 데이터의 크기 */

int compare(const void *a, const void *b);

main()
{
	char table[TABLESIZE][ELEMENTSIZE] = { "Hello", "Linux", "C" };
	char *ptr;
	int datanum=3;

	/* table에서 "Linux"를 탐색하고 찾은 데이터에 대한 포인터 반환 */
	if((ptr=(char *)lfind("Linux", table, &datanum, ELEMENTSIZE, compare))==NULL)
		printf("Not found\n");
	else 
		printf("%s\n", ptr);

	/* table에 "Programming"이 없으면 NULL 반환 */
	if((ptr=(char *)lfind("Programming", table, &datanum, ELEMENTSIZE, compare))==NULL)
		printf("Not found\n");
	else 
		printf("%s\n", ptr);
}

int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
