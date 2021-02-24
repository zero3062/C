void output_file(FILE *fp)
{
	int ch, line=1;

	if(flag)
		printf("1   ");
	while((ch=getc(fp)) != EOF) {
		if(flag&&ch=='\n') {
			if((ch=getc(fp))==EOF)
				break;
			ungetc(ch, fp);
			printf("\n%-4d", ++line);
		} else
			putc(ch, stdout);
	}
	printf("\n");
}
