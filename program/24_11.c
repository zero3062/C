#include <stdio.h>
#include <unistd.h>

main()
{
	/*무한 반복*/
	while (1) {
		printf("running\n");
		sleep(5);
	}
}
