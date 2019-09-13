#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	//CREATE
	key_t key = ftok("test", 2);
	//int shmget(key_t key, size_t size, int shmflg);
	int smid = shmget(key, 1024, 0777|IPC_CREAT);

	//ATTACH
	//void* shamt(int shmid, const void *shmaddr, int shmflg)
	char *str = (char*)shmat(smid, 0, 0);
	while(1){
		printf("Enter the data:\n");
		gets(str);
		if(strcmp(str, "bye") == 0)
			break;
	}
	//DETACH
	shmdt(str);

		
	return 0;
}
