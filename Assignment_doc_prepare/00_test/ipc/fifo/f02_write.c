#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
	/*int fd = mkfifo("FIFO_1", 0777);
	if(fd == -1){
		perror("mkfifo");
		exit(0);
	}*/
	char writeMsg[20];
	int fd = open("FIFO_1", O_WRONLY, 0776);
	while(1){
		memset(writeMsg, 0, sizeof(writeMsg));
		printf("The Message to parent:\n");	
		scanf("%s", &writeMsg);
		write(fd, writeMsg, sizeof(writeMsg));
	}
	return 0;	
}
