#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE 1024

int main()
{
	struct check_data{
		int check;
		char data[SIZE];
	}*shared_data;
	int shmid;
	void *shmaddr;
	struct shmid_ds shm_stat;

	/*1234키의 공유 메모리 생성*/
	if((shmid=shmget((key_t)1234, sizeof(struct check_data), IPC_CREAT|0666)) == -1){
		perror("shimid failed");
		exit(1);
	}

	/*shmid 공유 메모리를 호출하여 프로세스 메모리 영역으로 첨부*/
	if((shmaddr=shmat(shmid, (void *)0, 0)) == (void *)-1) {
			perror("shmat failed");
			exit(1);
	}

	shared_data = (struct check_data *)shmaddr;
	/*cheak가 0이면 공유 메모리에 도착한 데이터가 없다는 의미*/
	shared_data->check = 0;

	while(1) {
		/*공유 메모리가 도착하면 */
		if(shared_data->check) {
			printf("data read from shared memory :%s", shared_data->data);
			sleep(1);
			shared_data->check = 0;
			/*읽은 데이터가 'quit'면 */
			if(!strcmp(shared_data->data, "quit")) {
				/*shmid 공유 메모리 정보를 얻어 shm_stat에 저장*/
				if(shmctl(shmid, IPC_STAT, &shm_stat) == -1){
					perror("shmctl failed");
					exit(1);
				}
				/*공유 메모리를 이용하는 프로세스가 자식밖에 없으면 while문 벗어남*/
				if(shm_stat.shm_nattch==1)
					break;
			}
		}
		sleep(1);
	}
		
	/*공유 메모리를 호출 프로세스의 메모리 영역에서 분리*/
	if(shmdt(shmaddr) == -1) {
		perror("shmdt failed");
		exit(1);
	}

	/*shmid 공유 메모리 삭제*/
	if(shmctl(shmid, IPC_RMID, 0) == -1) {
		perror("shmct1 failed");
		exit(1);
	}
	exit(0);
}
