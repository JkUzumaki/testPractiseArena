#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	mkfifo("FIFO", 0777);
	int fd = open("FIFO", O_CREAT|O_WRONLY); 
	if(fd == -1){
		printf("mkfifo has failed\n");
		return -1;
	}
	char str[20];
	while(1){
		printf("Enter the data:\n");
		scanf("%s", &str);
		write(fd, str, 20);
		sleep(5);
	}
/*
	char wMsg[20];
	char rMsg[20];
	if(fork()){
		//Parent process
		scanf("%s", &wMsg);
		write(fd, wMsg, 20);
		sleep(1);
	}else{
		//Child process
		read(fd, rMsg, 20);
		printf("%s\n",rMsg);
	}
*/	
	return 0;
}
