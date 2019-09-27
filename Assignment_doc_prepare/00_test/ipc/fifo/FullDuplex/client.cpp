#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
int main()
{
	int fd1 = open("FIFO1", O_RDWR);
	int fd2 = open("FIFO2", O_RDWR);
	if(fd1 == -1){
		std::cout << "cannot create FIFO1";
		return -1;
	}
	if(fd2 == -1){
		std::cout << "cannot create FIFO2";
		return -1;
	}
	char str1[20];
	char str2[20];
	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	std::cout << "Client before the transfer\n";
	while(1){
		//Read
		read(fd1, str1, sizeof(str1));
		std::cout << "Data received : " << str1 << std::endl;
		//Write
		std::cout << "Enter the data : ";
		//std::cin >> str2;
		gets(str2);
		write(fd2, str2,sizeof(str2));
	}
	return 0;
}
