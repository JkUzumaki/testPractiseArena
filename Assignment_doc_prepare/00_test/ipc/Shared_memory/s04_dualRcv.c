#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	//CREATE
	key_t key = ftok("test", 2);
	key_t key1 = ftok("test", 3);
	int smid = shmget(key, 20, 0777|IPC_CREAT);
	int smid1 = shmget(key1, 20, 0777|IPC_CREAT);

	//ATTACH
	char *str = (char*)shmat(smid, 0,0);
	char *str1 = (char*)shmat(smid1, 0, 0);
	if(fork()){
		//Output	
		while(1){
			sleep(5);
			puts(str);
			if(strcmp(str, "bye") == 0)
				break;
		}
	}else{
		//Input
		while(1){
			printf("Enter the data:\n");
			gets(str1);
			if(strcmp(str, "bye") == 0)
				break;
		}
	}
	//DETACH
	shmdt(str);
	shmdt(str1);
	//DESTROY SHAREDMEMORY
	shmctl(smid, IPC_RMID, 0);
	shmctl(smid1, IPC_RMID, 0);	
	return 0;
}
