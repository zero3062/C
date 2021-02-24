#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void repeat(int semid);
void p(int semid);
void v(int semid);
 
int main()
{
    int semid, i;
    union semun {
       int val;
       struct semid_ds *buf;
       unsigned short int *array;
    } arg;

    /* ������� 1���� 1234 Ű�� �������� ���� ���� */
    if((semid=semget((key_t)1234, 1, IPC_CREAT|0666)) == -1) {
       perror("semget failed");
       exit(1);
    }

    /* �������� ���� 1�� ���� */
    arg.val = 1;
    if(semctl(semid, 0, SETVAL, arg) == -1) {
       perror("semctl failed");
       exit(1);
    }

    /* 3���� �ڽ� ���μ��� ���� */
    for(i=0; i<3; i++) {
       if(!fork())
          repeat(semid);
    }

    /* 10�ʰ� ���� */
    sleep(10);
    /* semid �������� ���� */
    if(semctl(semid, 0, IPC_RMID, arg) == -1) {
       perror("semctl failed");
       exit(1);
    }
    exit(0);
}

void repeat(int semid)
{
    /* ���� �ʱ�ȭ�ϱ� */
    srand((unsigned int)getpid());
    p(semid);
    /* getpid()�� ���� ���μ����� ���μ��� ID�� ��ȯ */
    printf("%d process is using tool\n", getpid());
    /* ������ 5�� ���� ������ �� ���� ���� */
    sleep(rand()%5);
    printf("%d process is returning tool\n", getpid());
    v(semid);

    exit(0);
}
 
void p(int semid)
{
    struct sembuf pbuf;
    pbuf.sem_num = 0;
    pbuf.sem_op = -1;
    /* ���μ��� �����ϸ� �������� ���� ���� ���� */
    pbuf.sem_flg = SEM_UNDO;
    /* ���� �������� ���� semval 1 �����ϱ� */
    if(semop(semid, &pbuf, 1) == -1) {
       perror("semop failed");
       exit(1);
    }
}

void v(int semid)
{
    struct sembuf vbuf;
    vbuf.sem_num = 0;
    vbuf.sem_op = 1;
    vbuf.sem_flg = SEM_UNDO;
    /* ���� �������� ���� semval 1 �����ϱ� */
    if(semop(semid, &vbuf, 1) == -1) {
       perror("semop failed");
       exit(1);
    }
}
