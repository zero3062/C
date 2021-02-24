#include <stdio.h>
#include <string.h>

int main()
{
	char *quit = "quit";
	char *string;

	while(1) {
		printf("Input string ==> ");
		scanf("%s", string);

		if(!memcmp(string, quit, 4))
			break;
		printf("%s\n", string);
	}
}
