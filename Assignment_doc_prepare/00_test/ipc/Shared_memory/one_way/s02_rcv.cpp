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
	int smid = shmget(key, 1024, 0777|IPC_CREAT);
	
	//ATTACH
	char *str = (char*)shmat(smid, 0,0);
	while(1){
		sleep(5);
		puts(str);
		if(strcmp(str, "bye") == 0)
			break;
	}
	//DETACH
	shmdt(str);
	
	//DESTROY SHAREDMEMORY
	shmctl(smid, IPC_RMID, 0);
		
	return 0;
}
