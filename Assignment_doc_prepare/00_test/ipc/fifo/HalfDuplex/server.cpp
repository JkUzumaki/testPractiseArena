#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
	mkfifo("FIFO", 0777);
	int fd = open("FIFO", O_CREAT|O_WRONLY);
	if(fd == -1){
		std::cout << "mkfifo";
		return -1;
	}
	char str[20];
	memset(str, 0, sizeof(str));
	
	while(1){
		std::cout << "Enter the data\n";
		std::cin >> str;
		write(fd, str, sizeof(str));
	}
	return 0;
}
