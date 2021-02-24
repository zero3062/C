#include <stdio.h>

int main()
{
	for(int i=0;i<3;i++) {
		for(int j=1;j<9;j++) {
			for(int k=2;k<5;k++)
				if(k+(i*3)!=10)
					printf("%d x %d = %d\t", k+(i*3), j, (k+(i*3))*j);
			printf("\n");
		}
		printf("\n");
	}
}
