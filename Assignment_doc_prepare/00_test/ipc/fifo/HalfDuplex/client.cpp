#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd = open("FIFO", O_CREAT|O_RDONLY);
	if(fd == -1){
		std::cout << "cannot create via mkfifo";
		return -1;
	}
	char str[20];
	memset(str, 0, sizeof(str));
	std::cout << "Client before the transfer\n";
	while(1){
		read(fd, str, sizeof(str));
		std::cout << "string: " << str << std::endl;
		if(str.compare("bye") == 0){
			std::cout << "The process is compeleted thanks for using the service!\n";
			break;
		}
	}
	return 0;
}
