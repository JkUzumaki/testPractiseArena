//Fifo client
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define FIFO_FILE "fifo_TwoWay"
int main()
{
	int fd;
	int end_process;
	int stringlen;
	int read_bytes;
	char readbuf[80];
	char end_str[5];
	
	printf("FIFO_CLIENT: send messages, infinitely, to end enter \"end\"\n");
	fd = open(FIFO_FILE, O_CREAT | O_RDWR);						// Opening the fifo
	strcpy(end_str, "end");							
	
	while(1){
			printf("Enter string: ");
			fgets(readbuf, sizeof(readbuf), stdin);				// Data is obtained from the user and stored in readbuf
			stringlen = strlen(readbuf);					// Calculating the readbuf data length 
			readbuf[stringlen -1] = '\0';					// Adding a null char to end of the string
			end_process = strcmp(readbuf, end_str);				// Comparing the obtained string with end string

			if(end_process != 0){
				//WRITE
				write(fd, readbuf, strlen(readbuf));
				printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
				//READ
				read_bytes = read(fd, readbuf, sizeof(readbuf));
				readbuf[read_bytes] = '\0';
				printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
			} else {
				//WRITE
				write(fd, readbuf, strlen(readbuf));
				printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
				close(fd);
				break;
			}
		}
	
	return 0;
}
