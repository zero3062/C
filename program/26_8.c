#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE 1024

main()
{
    struct check_data {
       int check;
       char data[SIZE];
    } *shared_data;
    int shmid;
    void *shmaddr;
    char buffer[SIZE];

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

    shared_data = (struct check_data *)shmaddr;

    while(1) {
       /* �����޸��� check�� 1�̸� ��ٸ� */
       while(shared_data->check) {
          sleep(1);
          printf("waiting...\n");
       }
       printf("input data ==> ");
       fgets(buffer, SIZE, stdin);

       /* �����޸𸮿� ������ ���� */
       strncpy(shared_data->data, buffer, SIZE);
       shared_data->check = 1;
       /* �� �����Ͱ� ��quit���̸� while �� ��� */
       if(!strncmp(shared_data->data, "quit", 4)) {
          break;
       }
    }
    /* �����޸𸮸� ȣ�� ���μ����� �޸� �������� �и� */
    if(shmdt(shmaddr) == -1) {
       perror("shmdt failed");
       exit(1);
    }
    exit(0);
}