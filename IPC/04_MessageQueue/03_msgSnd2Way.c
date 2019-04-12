//msgSnd

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define PERMS 0644

struct my_msgbuf{
	long mtype;
	char mtext[200];
};

int main()
{
	struct my_msgbuf buf;
	int msqid;
	int len;
	int toend;
	key_t key;
	system ("touch msgq.txt");
	// Creates a file
	if( (key = ftok("msgq.txt", 'B')) == -1){
		perror("ftok");
		exit(1);
	}
	// creat msg queue, msg-id is stored  in msquid
	if( (msqid = msgget(key, PERMS | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}
	printf("message queue: ready to send messages.\n");
	printf("Enter lines of text, ^D to quit:\n");
	// msg type is provided here
	buf.mtype = 1;
	// fgets is used for reading a string with spaces
	
	if(fork()){
		while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL) {
			len = strlen(buf.mtext);
			if(buf.mtext[len - 1] == '\n')			// id Last char is next line char
				buf.mtext[len -1] = '\0';		// Assign null char to end of string
			if(msgsnd(msqid, &buf, len+1, 0) == -1)		// send the msg to the message queue
				perror("msgsnd");
			sleep(3);
		}		
	} else {
		while(1){
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
	}
	strcpy(buf.mtext, "end");	
	len = strlen(buf.mtext);				
	if(msgsnd(msqid, &buf, len+1, 0) == -1)	    // +1 deonte for \0 char
		perror("msgsnd");
	if(msgctl(msqid, IPC_RMID, NULL) == -1){    // IPC_RMID means remove msg queue immediately
		perror("msgctl");
		exit(1);
	}
	printf("message queue: done sending messages.\n");
	return 0;
}
