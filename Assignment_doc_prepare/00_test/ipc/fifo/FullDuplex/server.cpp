#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
int main()
{
	mkfifo("FIFO1", 0777);
	mkfifo("FIFO2", 0777);
	int fd1 = open("FIFO1", O_RDWR);
	int fd2 = open("FIFO2", O_RDWR);
	if(fd1 == -1 ){
		std::cout << "cannot open the FIFO1\n";
		return -1;
	}
	if(fd2 == -1 ){
		std::cout << "cannot open FIFO2\n";
		return -1;
	}
	char str1[20];
	char str2[20];
	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	
	while(1){
		//Write
		std::cout << "Enter the data\n";
		gets(str1);
		write(fd1, str1, sizeof(str1));
		//Read
		read(fd2, str2, sizeof(str2));
		std::cout << "Data received: " << str2 << std::endl;
	}
	return 0;
}
