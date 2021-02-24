#include <stdio.h>

int main()
{
	 int ch;

	 printf("Input character ==> ");
	 ch = getchar();

	 if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		 printf("alphbet character\n");
	 else if(ch>='0'&&ch<='9')
		 printf("numeric character\n");
	 else
		 printf("others\n");
}
