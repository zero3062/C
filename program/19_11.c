#include <stdio.h>

main()
{
	FILE *fp;

	if((fp=fopen("nodata", "r")) == NULL) {	/* fopen 함수 호출하여 오류가 발생하면 */
		perror("ERROR");
		exit(1);
	}
	exit(0);
}
