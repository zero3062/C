#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <signal.h>
#define SIZE 1024

int main()
{
	int shmid;
	void *shmaddr;
	struct shmid_ds shm_stat;

	/*1234키의 공유 메모리가 있으면 접근해서 식별자 얻음*/
	if((shmid=shmget((key_t)1234, SIZE, IPC_CREAT|0666)) == -1){
		perror("shimid failed");
		exit(1);
	}

	/*shmid 공유 메모리를 호출하여  프로세스 메모리 영역으로 첨부*/
	if((shmaddr=shmat(shmid, (void *)0, 0)) == (void *)-1) {
			perror("shmat failed");
			exit(1);
	}

	/*공유 메모리에 저장된  데이터 출력*/
	printf("data read from shared memory : %s\n", (char *)shmaddr);

	/*shmid 공유 메모리 정보를 얻어 shm_stat에 저장*/
	if(shmctl(shmid, IPC_STAT, &shm_stat) == -1) {
		perror("shmctl failed");
		exit(1);
	}
	
	/*공유 메모리를 호출 프로세스의 메모리 영역에서 분리*/
	if(shmdt(shmaddr) == -1) {
		perror("shmdt failed");
		exit(1);
	}

	/*shm_stat.shm_cpid 프로세스에게 SIGINT 시그널 보냄*/
	kill(shm_stat.shm_cpid,SIGINT);

	exit(0);
}
