#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd = mkfifo("FIFO", 0777);
	if(fd == -1){
		perror("mkfifo");
		exit(0);
	}

	char writeMsg[20];
	char readMsg[20];
	memset(writeMsg, 0, sizeof(writeMsg));
	memset(readMsg, 0, sizeof(readMsg));
	//Zombie process
	if(fork() == 0){
		//Child
		printf("The Message to parent:\n");	
		scanf("%s", &writeMsg);
		write(fd, writeMsg, sizeof(writeMsg));
		//sleep(1);
	}else{
		//Parent
		read(fd, readMsg, sizeof(readMsg));
		printf("The Message from child:\n");
		printf("%s\n", &readMsg);
	}
	return 0;	
}
