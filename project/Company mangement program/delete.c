int delete_company(int num) { //해당 num은 리스트를 출력하고 선택한 번호를 의미함.
	int fd, i, non_blank=0;
	
	if((fd=open("company.dat", O_RDWR, 0644))==-1)
		printf("file error!\n");
		
	int size = lseek(fd,0,SEEK_END)/772;

	struct Company delete[size], some[size];

	lseek(fd,0,SEEK_SET);

	for(i=0;i<size;i++) {
		read(fd, &delete[i], sizeof(delete[i]));
	}


	lseek(fd, 0, SEEK_SET);

	for(i=0;i<size;i++) {	//해당 for문은 리스트를 출력하는 것과 비슷함
		if(delete[i].employee == 0) {
			non_blank++; //non_blank는 리스트를 읽으면서 빈공간을 세는 변수를 의미
			continue;
		}

		if(i+1-non_blank == num) { //여기서 i+1-non_blank가 num과 같으면 해당 struct를 삭제함.
			lseek(fd, 772*i, SEEK_SET); 
			memset(&delete[i], 0, sizeof(delete[i]));
			write(fd, &delete[i], sizeof(delete[i]));
			break;
		}
	}

	close(fd);
	return 0;
}
