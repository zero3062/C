#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#define SIZE 1024

main()
{
    int shmid;
    void *shmaddr;
    struct shmid_ds shm_stat;

    /* 1234 Ű�� �����޸� ������ �����ؼ� �ĺ��� ���� */
    if((shmid=shmget((key_t)1234, SIZE, IPC_CREAT|0666)) == -1) {
       perror("shmid failed");
       exit(1);
    }

    /* shmid �����޸𸮸� ȣ�� ���μ��� �޸� �������� ÷�� */
    if((shmaddr=shmat(shmid, (void *)0, 0)) == (void *)-1) {
       perror("shmat failed");
       exit(1);
    }

    /* �����޸𸮿� ����� ������ ��� */
    printf("data read from shared memory : %s\n", (char *)shmaddr);

    /* shmid �����޸� ������ ��� shm_stat�� ���� */
    if(shmctl(shmid, IPC_STAT, &shm_stat) == -1) {
       perror("shmctl failed");
       exit(1);
    }

    /* �����޸𸮸� ȣ�� ���μ����� �޸� �������� �и� */
    if(shmdt(shmaddr) == -1) {
       perror("shmdt failed");
       exit(1);
    }

    /* shm_stat.shm_cpid ���μ������� SIGINT �ñ׳� ���� */
    kill(shm_stat.shm_cpid, SIGINT);

    exit(0);
}