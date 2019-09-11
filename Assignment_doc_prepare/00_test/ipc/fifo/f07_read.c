//READ
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
	char readMsg[20];
	int str = 0;
	int fd = 0;
	int fd1 = 0;
	memset(readMsg, 0, sizeof(readMsg));
	fd = mkfifo("FIFO_1", 0777);
	char writeMsg[20];
	fd = open("FIFO_1", O_RDWR,0777);
	fd1 = open("FIFO_2", O_RDWR, 0777);
	memset(writeMsg, 0, sizeof(writeMsg));
	memset(readMsg, 0, sizeof(readMsg));
	//process creation
	if(fork() ){
		while(1){
			//Read
			read(fd, readMsg, sizeof(readMsg));
			//sleep(1);
			//printf("The Message to Child:\n");	
			str = strlen(readMsg);
			readMsg[str+1] = '\0';
			printf("%s\n", readMsg);
		}
	}else{
		while(1){	
			//Write
			//printf("The Message to parent:\n");	
			scanf("%s", &writeMsg);
			write(fd1, writeMsg, sizeof(writeMsg));
		}
	}
	return 0;	
}
