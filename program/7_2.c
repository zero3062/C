#include <stdio.h>
/* 매개변수가 있는 매크로에 대한 정의로 MAX와 (A, B)사이에 공백이 있어서는 안된다.*/
#define MAX(A,B) ((A)>(B) ? (A) : (B)) /* 매개변수가 있는 매크로 정의 */

main()
{
	int i, j;
	printf("Input two integer ==> ");
	scanf("%d %d", &i, &j);
	/* 매크로를 이용해 전처리하면 MAX(i, j)가 ((i)>(j) ? (i) : (j))로 바뀐다. */
	printf("max number : %d\n", MAX(i, j));
}
