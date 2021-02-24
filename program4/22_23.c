#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*루트 디렉토리를 /home/jkim/book/linux/chap22로 변경*/
	if(chroot("/home/jkim/book/liunx/chap22") == -1) {
		perror("chroot failed");
		exit(1);
	}
	if(chdir("/") == -1) {/*루트 디렉토리로 이동 */
		perror("chdir failed");
		exit(1);
	}
	if(mkdir("rootsub", 0777) == -1) { /*rootsub 디렉토리 생성 */
		perror("mkdir faile");
		exit(1);
	}
	exit(0);
}
