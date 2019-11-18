#include<iostream>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	key_t key = ftok("sm", 1);
	int shm = shmget(key, 100, 077|IPC_CREAT);
	char* str = (char*) shmat(shm, 0, 0);
	while(1){
		sleep(3);
		std::cout << str <<std::endl;
		if(strcmp(str, "over") == 0)
			break;
	}
	shmdt(str);
	return 0;
}
