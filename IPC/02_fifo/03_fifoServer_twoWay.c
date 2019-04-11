//Fifo Server
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define FIFO_FILE "fifo_TwoWay"

void reverse_string(char* );
int main()
{
	int fd;
	char readbuf[80];
	char end[10];
	int to_end;
	int read_bytes;

	mkfifo(FIFO_FILE, S_IFIFO | 0777);					// Creating a fifo
	strcpy(end, "end");
	fd = open(FIFO_FILE, O_RDWR);						// Opening the fifo in read write mode
	while(1){
		// READ
		read_bytes = read(fd, readbuf, sizeof(readbuf));		// Number of bytes read is returned	
		readbuf[read_bytes] = '\0';					// Null char to indicate the end of the string
		printf("FIFOSERVER: Receiving data : \"%s\" and length is %d\n", readbuf, (int) strlen(readbuf));
		to_end = strcmp(readbuf, "end");				// Check the read data is equal to end of the string

		if(to_end == 0){						
			close(fd);						// When string is equal to closing data, close the file descriptor
			break;
		}
		reverse_string(readbuf);					// Calling the reverse string function
		printf("FIFOSERVER: Sending Reversed string: \"%s\" and lenght is %d\n", readbuf, (int) strlen(readbuf));
		//WRITE
		write(fd, readbuf, strlen(readbuf));				// Writing to fifo
		sleep(2);
	}
	return 0;
}

void reverse_string(char* str)
{
	int last, limit, first;
	char temp;
	last = strlen(str) - 1;
	limit = last / 2;
	first = 0;

	while(first < last){
		temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		first++;
		last--;
	}
	return;
}
