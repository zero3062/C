#include <stdio.h>
#include <stdlib.h>	/* getenv 함수를 정의하는 헤더 파일 */

main()
{
	char *home_dir, *work_dir, *tmp;

	/* getenv를 이용해 HOME에 대한 환경 변수값 얻어옴 */
	if((home_dir=getenv("HOME"))!=NULL)
		printf("home directory : %s\n", home_dir);
	/* getenv를 이용해 PWD에 대한 환경 변수값 얻어옴 */
	if((work_dir=getenv("PWD"))!=NULL)
		printf("working directory : %s\n", work_dir);
	/* LINUX라는 환경 변수가 없으므로 NULL을 반환 */
	if((tmp=getenv("LINUX"))!=NULL)
		printf("temp : %s\n", tmp);
}
