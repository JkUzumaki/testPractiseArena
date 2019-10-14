#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdio.h>

struct msg_buff{
	long mtype;
	char mtext[20];
}msg;

int main()
{
	key_t key = ftok("progfile", 3);
	int fd = msgget(key, 0777|IPC_CREAT);
	msg.mtype=1;
	
	msgrcv(fd, &msg,sizeof(msg), 1, 0);
	
	printf("Message received to the queue: %s\n", msg.mtext);
	msgctl(fd, IPC_RMID, NULL);
	return 0;	
}
