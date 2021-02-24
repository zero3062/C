#include <stdio.h>
#include <stdlib.h>	/* bsearch 함수가 정의된 헤더 파일 */
#include <string.h> /* strcmp 함수가 정의된 헤더 파일 */

#define TABLESIZE 5 /* 테이블 크기 */
#define ELEMENTSIZE 10 /* 데이터의 크기 */

int compare(const void *a, const void *b);

main()
{
	/* table은 정렬되어 있어야 함 */
	char table[TABLESIZE][ELEMENTSIZE] = { "C", "Html", "Java", "Perl", "XML" };
	char *ptr;

	/* table에서 "Java"를 이진 탐색하고 찾은 데이터에 대한 포인터 반환 
	 만약 발견하지 못하면 NULL을 반환 */
	if((ptr=(char *)bsearch("Java", table, TABLESIZE, ELEMENTSIZE, compare))==NULL)
		printf("Not found\n");
	else 
		printf("%s\n", ptr);

	/* table에 "Linux"이 없으면 NULL 반환 */
	if((ptr=(char *)bsearch("Linux", table, TABLESIZE, ELEMENTSIZE, compare))==NULL)
		printf("Not found\n");
	else 
		printf("%s\n", ptr);
}

int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
