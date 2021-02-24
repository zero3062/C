#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	int count=0;

	while(1) {
		printf("Hello World\n");
		count++;

		if(count==3) {
			raise(SIGINT);
		}
		sleep(2);
	}
}
