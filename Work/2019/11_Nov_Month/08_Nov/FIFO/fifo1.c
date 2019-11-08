#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
	int fd = open("FIFO", 0777);
	if(fd == -1){
		printf("mkfifo has failed\n");
		return -1;
	}
	char str[20];
	while(1){
		read(fd, str, 20);
		printf("The received data: %s\n", str);
		sleep(5);
	}
/*
	char wMsg[20];
	char rMsg[20];
	if(fork() == 0){
		//Child process
		read(fd, rMsg, 20);
		printf("%s\n", rMsg);
	}else{
		//Parent process
		scanf("%s", &wMsg);
		write(fd, wMsg, 20);
		sleep(1);
	}
*/
	return 0;
}
