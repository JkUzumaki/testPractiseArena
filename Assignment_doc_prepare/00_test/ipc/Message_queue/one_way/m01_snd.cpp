#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdio.h>

	struct msgbuff{
		long mtype;
		char mtext[20];
	}msg;
int main()
{

	key_t key = ftok("progfile", 3);
	int fd = msgget(key, 0777|IPC_CREAT);

	//while(1){
		//msgsnd (msgid, cosnt void *msgp, size_t msgz, int msgflg)
		msg.mtype = 1;
		//msg.mtext = "Hello";
		printf("Enter data:\n");
		scanf("%s", msg.mtext);
		msgsnd(fd, &msg,sizeof(msg), 0);

	//}
	printf("Message added to the queue: %s\n", msg.mtext);
	return 0;	
}

