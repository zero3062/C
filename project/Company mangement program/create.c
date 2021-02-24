int new_create()
{	
	struct Company data;

	printf("기업을 입력해주세요\n");
	int fd, success = 0;
	char info[5][20] = {"company's name", "company's address", "company's employee", "company's CEO", "company's field"};
	
	if((fd=open("company.dat", O_RDWR | O_CREAT, 0644))==-1)
		printf("file error!\n");

	for(int i=0;i<lseek(fd, 0, SEEK_END)/772;i++) {
		lseek(fd,772*i, SEEK_SET);
		read(fd, &data, sizeof(data));

		if(data.employee == 0) {
			lseek(fd, 772*i, SEEK_SET);
			bzero(&data, sizeof(data));
	
			printf("%s\n",info[0]);
			readline(data.name, 128);

			printf("%s\n",info[1]);
			readline(data.address, 256);
	
			printf("%s\n",info[2]);
			scanf("%d", &data.employee);
	
			printf("%s\n",info[3]);
			readline(data.CEO, 128);
	
			printf("%s\n",info[4]);
			readline(data.field, 256);
	
			write(fd, &data, sizeof(data));
			success = 1;
			break;
		}
	}

	if(success == 0) {
		lseek(fd, 0, SEEK_END);
		bzero(&data, sizeof(data));
	
		printf("%s\n",info[0]);
		readline(data.name, 128);

		printf("%s\n",info[1]);
		readline(data.address, 256);
	
		printf("%s\n",info[2]);
		scanf("%d", &data.employee);
	
		printf("%s\n",info[3]);
		readline(data.CEO, 128);
	
		printf("%s\n",info[4]);
		readline(data.field, 256);
	
		write(fd, &data, sizeof(data));
	}

	close(fd);
	printf("\n");

	return 0;
}
