int get_company(int num)
{
	char ch[50];
	int fd, i, non_blank=0;

	if((fd=open("company.dat", O_RDONLY, 0644))==-1)
		printf("file error!\n");
	
	int size = lseek(fd, 0, SEEK_END)/772;

	struct Company info[size];

	lseek(fd,0,SEEK_SET);

	for(i=0;i<size;i++)
		read(fd, &info[i], sizeof(info[i]));

	lseek(fd, 0, SEEK_SET);

	for(i=0;i<size;i++) {	
		if(info[i].employee == 0) {
			non_blank++;
			continue;
		}

		if(i+1-non_blank == num) {
			printf("\n%-8s : %s\n", "name", info[i].name);
			printf("%-8s : %s\n", "address", info[i].address);
			printf("%-8s : %d\n", "employee", info[i].employee);
			printf("%-8s : %s\n", "CEO", info[i].CEO);
			printf("%-8s : %s\n", "field", info[i].field);
			break;
		}
	}

	printf("\n수정하기(e)\n");
	printf("삭제하기(d)\n");
	printf("나가기(q)\n\n");

	printf("회사 정보 화면 입력 : ");

	while(1) {
		scanf("%s", ch);
		if((ch[0] == 'e')&&(strlen(ch)==1)) {
			edit_company(num);
			break;
		} else if((ch[0]=='d')&&(strlen(ch)==1)) {
			delete_company(num);
			break;
		} else if((ch[0]=='q')&&(strlen(ch)==1)) {
			break;
		} else 
			printf("\n회사 정보 화면 재입력 : ");
	}

	close(fd);
	return 0;
}
