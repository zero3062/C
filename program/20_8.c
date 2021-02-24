void output_file(FILE *fp)
{
	int ch, line=1;

	if(flag)
		printf("1   ");
	while((ch=getc(fp))!=EOF) {
		if(flag && ch=='\n') {
			/* 다음 문자가 EOF면 출력하지 않고 빠져 나옴 */
			if((ch=getc(fp))==EOF)
				break;
			/* ch를 fp 파일로 되돌림 */
			ungetc(ch, fp);
			printf("\n%-4d", ++line);
		} else 
			putc(ch, stdout);
	}
	printf("\n");
}
