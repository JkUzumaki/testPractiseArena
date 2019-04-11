#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "FIFO1"

int main()
{
	int fd;
	int end_process;
	int stringlen;
	char readbuf[80];
	char end_str[5];
	printf("FIFO_CLIENT: Send messages, infinitely, to end enter\" end\"\n");
	fd = open(FIFO_FILE, O_CREAT | O_WRONLY);	// Opening the file in in Write only mode. Create it if not created.
	strcpy(end_str, "end");				// Copying the string to end_str
	while(1){
		printf("Enter string:\n");		
		fgets(readbuf, sizeof(readbuf), stdin);	// Readbuf contians the string 
		stringlen = strlen(readbuf);		// Length of the string
		readbuf[stringlen -1] = '\0';		// Inserting the null char 
		end_process = strcmp(readbuf, end_str); // Comparing the string to the end char

		if(end_process != 0){			// Will not break the contuination if this condition is not satisfied
			write(fd, readbuf, strlen(readbuf));	// Writing the data to buffer
			printf("Sent string: \"%s\" and string length is %d\n", readbuf,(int) strlen(readbuf));
		} else {				// Will break the loop when if condition fails
			write(fd, readbuf, strlen(readbuf));	// Writing the data to buffer
			printf("Sent string: \"%s\" and string length is %d\n", readbuf, (int) strlen(readbuf));	
			close(fd);			// Closing the file descriptor
			break;
		}
	}
	return 0;
}
