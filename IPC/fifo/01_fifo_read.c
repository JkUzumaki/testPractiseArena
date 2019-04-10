#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//Naming the fifo file
#define FIFO_FILE "FIFO1"
int main()
{
	int fd;
	char readbuf[80];
	char end[10];
	int to_end;
	int read_bytes;
	//Creating a fifo file
	mkfifo(FIFO_FILE, S_IFIFO | 0777);				
	strcpy(end, "end");
	while(1){
		fd = open(FIFO_FILE, O_RDONLY);				// Open the fifo file in read only mode
		read_bytes = read(fd, readbuf, sizeof(readbuf));	// Read the data from the buffer and returns the number of char read
		readbuf[read_bytes] = '\0';				// Adding null char to denote the end of the string
		printf("Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));	// readbuf contains the data read
		to_end = strcmp(readbuf, end);				//Compaing the read data to end
		if(to_end == 0){					// is compared data is end
			close(fd);					// close the file descriptor
			break;			
		}
	}
	return 0;
}
