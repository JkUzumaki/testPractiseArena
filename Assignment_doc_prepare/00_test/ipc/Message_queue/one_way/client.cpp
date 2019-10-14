#include<iostream>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

int main()
{
	key_t key = ftok("test", 1);
	int fd = msgget(key, 0777|IPC_CREAT);
	struct test{
		long mtype;
		char mtext[20];
	};
	test msg;
	msg.mtype = 1;
	std::cout << "Message added \n";
	msgrcv(fd, &msg,sizeof(msg), 1, 0);
	std::cout << "Message received " << msg.mtext << std::endl;
	//msgctl(fd, IPC_RMID, NULL);
	return 0;
}
