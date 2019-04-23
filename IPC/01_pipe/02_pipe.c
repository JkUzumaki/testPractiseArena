#include<stdio.h>
#include<unistd.h>

int main()
{
	// pipe read end -> 0
	// pipe write end -> 1
	int p[2];
	int status;
	int pid;
	// checking is pipe is created using the pipe system call
	status = pipe(p);
	if(status == -1){
		printf("Pipe not created\n");
		return 1;
	}
	pid = fork();
	if(pid){
		/*
			Parent process is generally started first
			if in case read operation is present in the parent, since nothing is wirtten 
			in the pipe the read will block the parent process and move to the child process
		 	and write data into the buffer.
		*/
		printf("\nCHILD PROCESS\n");
		char readmsg[25];
		read(p[0], readmsg, sizeof(readmsg));
		printf("Child process - Reading from pipe - message 1 is %s\n", readmsg);
	} else {
		printf("\nPARENT PROCESS\n");
		char writemsg[25] = "Hello Jayakumar!";
		printf("Parent process - writing to pipe - message 1 is %s\n", writemsg);
		write(p[1], writemsg, sizeof(writemsg));
	}
	return 0;
}
