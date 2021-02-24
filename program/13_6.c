#include <stdio.h>
#include <stdlib.h> /* qsort 함수가 정의된 헤더 파일 */
#include <string.h> /* strcmp 함수가 정의된 헤더 파일 */

#define TABLESIZE 5 /* 테이블 크기 */
#define ELEMENTSIZE 15 /* 데이터의 크기 */

int compare(const void *a, const void *b);

main()
{
	int i;
	char table[TABLESIZE][ELEMENTSIZE] = { "Hello", "Linux", "C", "Programming", "Java" };

	/* table을 퀵 정렬 */
	qsort(table, TABLESIZE, ELEMENTSIZE, compare);

	/* 정렬된 테이블 출력 */
	for(i=0; i<TABLESIZE; i++)
		printf("%s\n", table[i]);
}

/* a와 b를 비교해 a가 작으면 음수를, 같으면 0을, 크면 양수를 반환 */
int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
