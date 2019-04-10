#include<stdio.h>
#include<unistd.h>

int main()
{
	int p[2];
	int p1[2];
	int status;
	int pid;
	status = pipe(p);
	if(status == -1){
		printf("Pipe p not created\n");
		return 1;
	}
	
	status = pipe(p1);
	if(status == -1){
		printf("Pipe p1 not created\n");
		return 1;
	}
	
	pid = fork();
	if(pid == 0){
		/*
			Parent process is generally started first
			if in case read operation is present in the parent, since nothing is wirtten 
			in the pipe the read will block the parent process and move to the child process
		 	and write data into the buffer.
		*/
		printf("\nCHILD PROCESS\n");
		//READ
		char readmsg[25];
		read(p[0], readmsg, sizeof(readmsg));
		printf("Child process - Reading from pipe - message 1 is %s\n", readmsg);
		//WRITE
		char writemsg[25] = "Harigot gosaimasu!";
		
		printf("Child process - writing to pipe - message 2 is %s\n", writemsg);
		write(p1[1], writemsg, sizeof(writemsg));
	} else {
		printf("\nPARENT PROCESS\n");
		//WRITE
		char writemsg[25] = "Hello Jayakumar!";
		printf("Parent process - writing to pipe - message 1 is %s\n", writemsg);
		write(p[1], writemsg, sizeof(writemsg));
		//READ
		char readmsg[25];
		read(p1[0], readmsg, sizeof(readmsg));
		printf("Parent process - Reading from pipe - message 2 is %s\n", readmsg);
		
	}
	return 0;
}
