#include <stdio.h>

int main()
{
	 char ch;
	 while((ch=getchar())!= EOF)
		 printf("%c", ((ch>='A')&&(ch<='Z'))?ch-'A'+'a' :ch);
}
