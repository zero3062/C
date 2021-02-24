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

    /* 1234 키의 공유메모리 있으면 접근해서 식별자 얻음 */
    if((shmid=shmget((key_t)1234, SIZE, IPC_CREAT|0666)) == -1) {
       perror("shmid failed");
       exit(1);
    }

    /* shmid 공유메모리를 호출 프로세스 메모리 영역으로 첨부 */
    if((shmaddr=shmat(shmid, (void *)0, 0)) == (void *)-1) {
       perror("shmat failed");
       exit(1);
    }

    shared_data = (struct check_data *)shmaddr;

    while(1) {
       /* 공유메모리의 check가 1이면 기다림 */
       while(shared_data->check) {
          sleep(1);
          printf("waiting...\n");
       }
       printf("input data ==> ");
       fgets(buffer, SIZE, stdin);

       /* 공유메모리에 데이터 쓰기 */
       strncpy(shared_data->data, buffer, SIZE);
       shared_data->check = 1;
       /* 쓴 데이터가 ‘quit’이면 while 문 벗어남 */
       if(!strncmp(shared_data->data, "quit", 4)) {
          break;
       }
    }
    /* 공유메모리를 호출 프로세스의 메모리 영역에서 분리 */
    if(shmdt(shmaddr) == -1) {
       perror("shmdt failed");
       exit(1);
    }
    exit(0);
}