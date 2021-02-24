#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[10];
	int i, j;
	char list[2];

	printf("Input the integer ==> ");
	scanf("%s", str);
	
	for(i=1;i<10;i++){
		for(j=0;j<strlen(str);j++) {
			list[0]=str[j];
			printf("%c x %d = %d\t", str[j], i, atoi(list)*i);
		}
		printf("\n");
	}
}
