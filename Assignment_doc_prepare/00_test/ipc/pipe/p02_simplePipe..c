#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int p[2];
	int pipe(p);
	int fd = 0;
	fd = open("pipeFile", O_CREAT, 0777);

	if(fd == -1){
		printf("Cannot create pipe\n");
		exit(1);
	}

	char readMsg[20];
	char writeMsg[20];	
	memset(readMsg, 0, sizeof(readMsg));
	memset(readMsg, 0, sizeof(writeMsg));
	printf("Enter the data to the pipe:\n");
	write(p[1], writeMsg, sizeof(writeMsg));
	printf("data processing.....\n");
	sleep(4);
	printf("The data obtained through read end: ")	;
	read(p[0], readMsg, sizeof(readMsg));
	return 0;
}
