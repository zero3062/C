#include <stdio.h>
#include <string.h>

int main()
{
	int n;

	n = strspn("seoulKorea", "elmnopsu");
	printf("%d\n", n);
}
