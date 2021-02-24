#include <stdio.h>
#include <search.h> /* tsearch, twalk, tdelete 함수가 정의된 헤더 파일 */
#include <string.h> /* strcmp 함수가 정의된 헤더 파일 */

int compare(const void *a, const void *b);
void printtree(const void const *node, const VISIT order, 
const int depth);
main()
{
	void *root;
	root = NULL;

	/* root가 가리키는 트리에서 데이터를 찾은 후 없으면 트리에 삽입 */
	tsearch("Hello", &root, compare);
	tsearch("Linux", &root, compare);
	tsearch("C", &root, compare);
	/* root가 가리키는 트리를 방문하며, 구체적인 동작은 printree 함수에서 정의 */
	twalk(root, printtree);

	/* root가 가리키는 트리에서 "Hello"를 내용으로 하는 노드 삭제 */
	tdelete("Hello", &root, compare);
	twalk(root, printtree);
}

/* a와 b를 비교해 같으면 0을 반환 */
int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
/* postorder거나 leaf면 출력. 결국 알파벳순으로 트리의 모든 내용을 출력 */
void printtree(const void const *node, const VISIT order, 
const int depth)
{
	char *str;
	str = *(char **)node;

	/* postorder거나 leaf면 노드의 데이터를 출력 */
	if(order==postorder || order==leaf)
		printf("string : %s\n", str);
}
