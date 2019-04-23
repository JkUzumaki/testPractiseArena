#include<stdio.h>
#include<unistd.h>
#define SIZE 16

int main()
{
	char* input;
	char output[SIZE];
	int p[2];
	if(fork()){
		input = "Hello World!";
		write(p[1], input, SIZE);
//		sleep(2);
	} else {
//		sleep(1);
		read(p[0], output, SIZE);
		printf("The read data : %s\n", output);
	}
	return 0;
}

/*
	int pipe_name[2];
		pipe_name[1] -> write command
		pipe_name[0] -> read command
	write ( write_end_of_pipe, buffer, size of buffer)
	read ( read_end_of_pipe, buffer, size of buffer)
*/
