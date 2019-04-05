#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int n = 10;
	pid_t pid = vfork();
	if(pid == 0){
		printf("Child process started\n");
	} else {
		printf("Now i'm coming back to parent process\n");
	}
	printf("Value of n: %d\n", n);
	return 0;
}
