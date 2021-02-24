#include <stdio.h>
#define MAX 1024

int main()
{
	FILE *ifp, *ofp;
	char buffer[MAX];
	int num;

	ifp = fopen("source", "r");
	ofp = fopen("resule", "w");

	num = fread(buffer, 1, MAX, ifp);
	fwrite(buffer, 1, num, ofp);

	fclose(ifp);
	fclose(ofp);
}
