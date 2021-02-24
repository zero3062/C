int edit_company(int list_num) //list_num은 리스트를 출력했을 때 선택했던 번호
{
	printf("\nname edit(1) address edit(2) employee edit(3) CEO edit(4) field edit(5)\n");

	int fd, i, num;
	
	if((fd=open("company.dat", O_RDWR, 0644))==-1)
		printf("file error!\n");

	int size = lseek(fd,0,SEEK_END)/772;
	lseek(fd, 0, SEEK_SET);

	struct Company edit;

	bzero(&edit, sizeof(edit));
	
	printf("\n수정할 항목을 입력하세요 : ");
	scanf("%d", &num);

	char src[256];
	
	if(num!=3) { //수정할 항목이 employee가 아니면 
		printf("\n수정 사항 입력 : ");
		scanf(" %[^\n]s", src);
	}

	if(num==1) {
		char *dest1 = edit.name;
		
		memcpy(dest1, src, sizeof(char)*strlen(src)+1);
		lseek(fd, 772*list_num, SEEK_SET);
		write(fd, edit.name, sizeof(edit.name));
	} else if(num==2) {
		char *dest2 = edit.address;

		memcpy(dest2, src, sizeof(char)*strlen(src)+1);
		lseek(fd, 772*list_num+128, SEEK_SET);
		write(fd, edit.address, sizeof(edit.address));
	} else if(num==3) { //해당 변경사항이 employee임, 따라서 따로 int형 변수를 입력받음
		printf("\n수정 사항 입력 : " );
		scanf("%d", &edit.employee);

		lseek(fd, 772*list_num+384, SEEK_SET);
		write(fd, &edit.employee, sizeof(edit.employee));
	} else if(num==4) {
		char *dest4 = edit.CEO;
		
		memcpy(dest4, src, sizeof(char)*strlen(src)+1);
		lseek(fd, 772*list_num+388, SEEK_SET);
		write(fd, edit.CEO, sizeof(edit.CEO));
	} else if(num==5) {
		char *dest5 = edit.field;
		
		memcpy(dest5, src, sizeof(char)*strlen(src)+1);
		lseek(fd, 772*list_num+516, SEEK_SET);
		write(fd, edit.field, sizeof(edit.field));
	}

	close(fd);
	return 0;
}
