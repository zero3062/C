#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

main()
{
	/* 루트 디렉토리를 /home/jkim/book/linux/chap22로 변경 */
	if(chroot("/home/jkim/book/linux/chap22") == -1) {
		perror("chroot failed");
		exit(1);
	}
	if(chdir("/")==-1) {	/* 루트 디렉토리로 이동 */
		perror("chdir failed");
		exit(1);
	}
	if(mkdir("rootsub", 0777)==-1) { 	/* rootsub 디렉토리를 생성 */
		perror("mkdir failed");
		exit(1);
	}
	exit(0);
}
