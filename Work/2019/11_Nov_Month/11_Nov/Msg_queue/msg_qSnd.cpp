#include<iostream>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>


int main()
{
	key_t key = ftok("kk", 1);
	int mq = msgget(key, 0777|IPC_CREAT);
	struct test{
		long mtype;
		char mtext[10];
	}obj;
	std::cout << "Enter the message:\n";
	std::cin >> obj.mtext;
	obj.mtype = 9;
	int len = strlen(obj.mtext);
	if(msgsnd(mq, &obj, sizeof(obj), 0) == -1){
		perror("msgsnd");
		exit(1);	
	}
	std::cout << "MsgQueue done sending the messages\n";
	return 0;
}
