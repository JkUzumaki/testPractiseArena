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
	memset(writeMsg, 0, sizeof(writeMsg));
	printf("\nreadMsg contains : %s", readMsg);
	printf("\nwriteMsg contains : %s", writeMsg);
	printf("\nEnter the data to the pipe:");
	scanf("%s", &writeMsg);
	write(p[1], writeMsg, sizeof(writeMsg));
	printf("\nwriteMsg contains : %s", writeMsg);
	printf("\nreadMsg contains : %s", readMsg);
	printf("\data processing.....");
	sleep(2);
	printf("\nThe data obtained through read end: ")	;
	sleep(1);
	read(p[0], readMsg, sizeof(readMsg));
	printf("\nreadMsg contains : %s", readMsg);
	return 0;
}
