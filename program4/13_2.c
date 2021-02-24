#include <stdio.h>
#include <search.h>/*lfind함수가 정의된 헤더파일*/
#include <string.h> /*strcmp함수가 정의된 헤더파일*/

#define TABLESIZE 10 /*테이블의 크기*/
#define ELEMENTSIZE 15 /*데이터 크기*/

int compare (const void *a, const void *b);

int main()
{
	char table[TABLESIZE][ELEMENTSIZE] = {"Hello", "Linux", "C"};
	char *ptr;
	size_t  datanum=3;

	/*table에서 "Linux"를 탐색하고 찾은 데이터에 대한 포인터 반환*/
	if((ptr=(char *)lfind("Linux", table, &datanum, ELEMENTSIZE, compare))==NULL)
		printf("Not found\n");
	else
		printf("%s\n", ptr);
}

int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

