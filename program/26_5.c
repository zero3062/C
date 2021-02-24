#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#define SIZE 1024

void signalHandler(int signo);
int shmid;

main()
{
    void *shmaddr;

    /* 1234 Ű�� �����޸� ���� */
    if((shmid=shmget((key_t)1234, SIZE, IPC_CREAT|0666)) == -1) {
       perror("shmid failed");
       exit(1);
    }

    /* shmid �����޸𸮸� ȣ�� ���μ��� �޸� �������� ÷�� */
    if((shmaddr=shmat(shmid, (void *)0, 0)) == (void *)-1) {
       perror("shmat failed");
       exit(1);
    }

    /* �����޸𸮿� ������ ���� */
    strcpy((char *)shmaddr, "Linux Programming");

    /* �����޸𸮸� ȣ�� ���μ����� �޸� �������� �и� */
    if(shmdt(shmaddr) == -1) {
       perror("shmdt failed");
       exit(1);
    }

    /* SIGINT �ñ׳� ������ signalHandler �����ϵ��� ���� */
    signal(SIGINT, signalHandler);
    pause();
}

void signalHandler(int signo)
{
    /* shmid �����޸� ���� */
    if(shmctl(shmid, IPC_RMID, 0) == -1) {
       perror("shmctl failed");
       exit(1);
    }
    exit(0);
}