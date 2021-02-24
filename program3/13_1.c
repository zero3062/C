#include <stdio.h>
#include <search.h>
#include <string.h>

#define TABLESIZE 10
#define ELEMENTSIZE 15

int compare(const void *a, const void *b);

int main()
{
	char table[TABLESIZE][ELEMENTSIZE]={"Hello", "Linux", "C"};
	char *ptr;
	size_t datanum=3;

	ptr = (char *)lsearch("Linux", table, &datanum, ELEMENTSIZE, compare);
	printf("%s\n", ptr);

	ptr = (char *)lsearch("Programming", table, &datanum, ELEMENTSIZE, compare);
	printf("%s\n", ptr);
}

int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
