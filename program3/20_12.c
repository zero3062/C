#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *home_dir;

	if((home_dir=getenv("HOME"))!=NULL)
		printf("home directory : %s\n", home_dir);

	putenv("HOME=/home/jkim/book/linux");

	if((home_dir=getenv("HOME"))!=NULL)
		printf("home directory : %s\n", home_dir);
}
