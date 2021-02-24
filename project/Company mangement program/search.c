int search_company(char *data) //data는 리스트를 뽑고 입력한 문자열 배열을 의미
{
	int fd, size, i, find=0;

	if((fd=open("company.dat", O_RDONLY, 0644))==-1)
		printf("file error!\n");
	
	size = lseek(fd, 0, SEEK_END);

	struct Company search_list[size/772];

	lseek(fd, 0, SEEK_SET);

	for(i=0;i<size/772;i++) {
		bzero(&search_list[i], sizeof(search_list[i]));
		read(fd, &search_list[i], sizeof(search_list[i]));

		if(strstr(data, search_list[i].name)&&(strlen(data)==strlen(search_list[i].name))) {
			find = 1;
			break;
		}
	}

	if(find==1)
		get_company(i+1);
	else 
		printf("\n찾지 못했습니다.\n");

	return 0;
}
