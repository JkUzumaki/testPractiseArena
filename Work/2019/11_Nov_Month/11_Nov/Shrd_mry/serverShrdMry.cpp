#include<iostream>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
	key_t key = ftok("sm", 1);
	int shm = shmget(key, 100, 0777|IPC_CREAT);
	//Attach
	char *str = (char*)shmat(shm, 0, 0);
	while(1){
		std::cout << "Enter the data:\n";
		std::cin >> str;
		if(strcmp(str, "over") == 0)
			break;
	}
	shmdt(str);
	return 0;
}
