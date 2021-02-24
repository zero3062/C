#include <stdio.h>

main()
{
	union position {	/* 공용체 정의 */
		int class;
		char department[10];
	} my;	/* 변수 선언 */
	int chk;

	printf("select number (highschool : 1, university :2) ==> ");
	scanf("%d", &chk);

	if(chk == 1) {	/* 고등학생이면 */
		printf("class ==> ");
		scanf("%d", &(my.class));
	} else { /* 대학생이면 */
		printf("class ==> ");
		scanf("%d", &(my.department));
	}

	if(chk == 1) { /* 고등학생이면 */
		printf("highschool : %d class\n", my.class);
	} else {	/* 대학생이면 */
		printf("university : %ds major\n", my.department);
	}
}
