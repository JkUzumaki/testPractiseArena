//WRITE
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
	char writeMsg[20];
	char readMsg[20];
        mkfifo("FIFO_2", 0777);	
	int fd = open("FIFO_1", O_RDWR, 0777);
	int fd1 = open("FIFO_2", O_RDWR, 0777);
	int str = 0;

	//Memeory clear
	memset(readMsg, 0, sizeof(readMsg));
	memset(writeMsg, 0, sizeof(writeMsg));
	//process creation
	if(fork() == 0){
		while(1){
			//Write
			//printf("The Message to parent:\n");	
			scanf("%s", &writeMsg);
			write(fd, writeMsg, sizeof(writeMsg));
		}
	}else{
		while(1){	
			//Read
			read(fd1, readMsg, sizeof(readMsg));
			//sleep(1);
			//printf("The Message to Child:\n");	
			str = strlen(readMsg);
			readMsg[str+1] = '\0';
			printf("%s\n", readMsg);
			//puts(readMsg);
		}
	}
	
	return 0;	
}
