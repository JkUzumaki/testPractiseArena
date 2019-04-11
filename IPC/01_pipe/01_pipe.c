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
