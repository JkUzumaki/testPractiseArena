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
	memset(readMsg, 0, sizeof(readMsg));
	fd = mkfifo("FIFO_1", 0777);
	
	fd = open("FIFO_1", O_RDONLY,0777);
	while(1){
		printf("The Message to Child:\n");	
		read(fd, readMsg, sizeof(readMsg));
		str = strlen(readMsg);
		readMsg[str+1] = '\0';
	//	printf("data: %s\n", readMsg);
		puts(readMsg);
	}
	return 0;	
}
