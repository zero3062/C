#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int i;
	char *arg[argc];
	printf("Running %s with execvp\n", argv[1]);
	/*명령라인에서 받아들인 인수를 arg로 복하는 부분으로
	  첫 번재 인수인  a.out은 제외*/
	for(i=0; i<(argc-1); i++) {
		arg[i] = argv[i+1];
	}
	/*인수가 더 없음을 의미하는 문자 추가 */
	arg[i] = (char *)0;
	/*execvp를 이용해 'ps -au'명령어가 실행되도록 하는 부분으로,  argv[1]에는
	  'ps'가 ,  arg[0]에는 'ps', arg[1]에는 '-au', 그리고 arg[2]에는 0이 저장*/
	execvp(argv[1], arg);
	printf("execvp failed to run %s\n", argv[i]);
	exit(0);
}
