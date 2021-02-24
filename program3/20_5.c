#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int opt;

	while((opt=getopt(argc, argv, "lf:ai"))!=-1) {
		switch(opt) {
			case 'l':
			case 'a':
			case 'i':
				printf("option: %c\n", opt);
				break;
			case 'f':
				printf("option %c's argument : %s\n", opt, optarg);
				break;
			case '?':
				printf("unknown option : %c\n", optopt);
		}
	}

	for(; optind<argc;optind++)
		printf("argument : %s\n", argv[optind]);
	exit(0);
}
