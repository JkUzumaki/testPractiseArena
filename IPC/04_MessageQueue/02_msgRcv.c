//msgRcv
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PERMS 0644
struct my_msgbuf {
   long mtype;
   char mtext[200];
};

int main()
{
	struct my_msgbuf buf;
	int msqid;
	int toend;
	key_t key;
	// Creates a file	
	if((key = ftok("msgq.txt", 'B')) == -1){
		perror("ftok");
		exit(1);
	}
	// Creates message queue
	if((msqid = msgget(key, PERMS)) == -1){

		perror("msgget");
		exit(1);
	}

	printf("message queue: ready to receive messages.\n");

	for(;;){// Infinite loop
		// Message queue received
		if(msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1){
			perror("msgrcv");
			exit(1);
		}
		// String is printed
		printf("recvd: \"%s\"\n", buf.mtext);
		toend = strcmp(buf.mtext, "end");
		if(toend == 0)
			break;
	}
	printf("message queue: done receiving messages.\n");
	system("rm msgq.txt");
	return 0;
}
