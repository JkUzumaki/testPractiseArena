#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	//CREATE
	key_t key = ftok("test", 2);
	key_t key1 = ftok("test", 3);
	//int shmget(key_t key, size_t size, int shmflg);
	int smid = shmget(key, 20, 0777|IPC_CREAT);
	int smid1 = shmget(key1, 20, 0777|IPC_CREAT);
	//ATTACH
	//void* shamt(int shmid, const void *shmaddr, int shmflg)
	char *str = (char*)shmat(smid, 0, 0);
	char *str1 = (char*)shmat(smid1, 0, 0);
	if(fork()){
		while(1){
			printf("Enter the data:\n");
			gets(str);
			if(strcmp(str, "bye") == 0)
				break;
		}
	}else{
		while(1){
			sleep(7);
			puts(str1);
		}
	}
	//DETACH
	shmdt(str);
	shmdt(str1);
		
	return 0;
}
