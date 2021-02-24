#include <stdio.h>
#include <search.h>

int main()
{
	ENTRY item;
	ENTRY *result;

	hcreate(5);

	item.key="Linux";
	item.data="Linux";
	
	hsearch(item, ENTER);
	item.key="C";
	item.data="C";
	hsearch(item, ENTER);
	item.key="Programming";
	item.data="Programming";
	hsearch(item, ENTER);
	
	item.key="Linux";
	item.data="LINUX";
	
	if((result=hsearch(item, FIND))==NULL)
		printf("Not found\n");
	else
		printf("Found : %p\n", item.data);

	item.key="Java";
	item.data="Java";
	if((result=hsearch(item,FIND))==NULL)
		printf("Not found\n");
	else
		printf("Found : %p\n", result->data);
}
