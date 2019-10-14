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
	msg.mtype = 10;
	std::cout <<"Enter data:\n";
	std::cin >> msg.mtext;
	msgsnd(fd, &msg, sizeof(msg), 0);
	std::cout << "Message addde to queue " << msg.mtext << "\n";
	return 0;
}
