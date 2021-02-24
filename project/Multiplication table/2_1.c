#include <stdio.h>

int main()
{
	int i, j, k;
	
	for(i=0;i<3;i++) {
		for(j=1;j<10;j++){
			for(k=2;k<5;k++){
				if(k+i*3!=10)
					printf("%d x %d = %d\t", k+i*3, j, (k+i*3)*j);
			}
			printf("\n");
		}
		printf("\n");
	}
}
