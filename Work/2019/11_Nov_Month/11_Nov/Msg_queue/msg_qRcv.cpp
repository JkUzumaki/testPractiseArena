#include<iostream>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

int main()
{
	key_t key = ftok("kk", 1);
	int mq = msgget(key , 0777|IPC_CREAT);
	struct test{
		long mtype;
		char mtext[20];
	}obj;
	obj.mtype = 9;
	msgrcv(mq, &obj, sizeof(obj),9 ,0);
	std::cout << "Message received: " << obj.mtext << std::endl;
	return 0;
}
