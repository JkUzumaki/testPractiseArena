#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd = mkfifo("FIFO",0777);
	if(fd == -1){
		std::cout << "mkfifo";
		return -1;
	}
	char str[20];
	memset(str, 0, sizeof(str));
	std::cout << "Client before the transfer\n";
	while(1){
		read(fd, str, sizeof(str));
		std::cout << "string: " << str << std::endl;
	}
	return 0;
}
