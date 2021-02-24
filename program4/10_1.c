#include <stdio.h>
#include <stdlib.h> /*malloc함수가 정의된 헤더 파일*/
#include <string.h> /*strcpy함수가 정의된 헤더 파일*/

int main()
{
	/*자기 참조 구조체 선언*/
	struct list{
		char name[10];
		int age;
		struct list *next;
	};
	struct list *ptr;

	/*struct list형 크기의 동적 메모리를 할당하고 ptr이 가리킴 */
	if((ptr=(struct list *)malloc(sizeof(struct list))) == NULL)
		exit(1); /*프로그램 종료*/
	strcpy(ptr -> name, "jkim");
	ptr -> age = 30;

	/*struct list형 크기의 동적 메모리를 할당하고 ptr->next가 가리킴*/
	if((ptr->next=(struct list *)malloc(sizeof(struct list))) == NULL)
		exit(1);
	strcpy(ptr -> next->name, "kang");
	ptr->next->age = 25;

	printf("%s's age : %d\n", ptr->name, ptr->age);
	printf("%s's age : %d\n", ptr->next->name, ptr->next->age);
}
