#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int p[2];
	int pipe(p);
	int fd = 0;
	fd = open("test", O_CREAT, 0777);
	if(fork()){
		char s1[20];
		memset(s1, 0, sizeof(s1));
		printf("The Message to child:\n");
		scanf("%s",&s1);
		getchar();
		write(p[1], s1, 20);
	}else{
		sleep(1);
		char s2[20];
		memset(s2, 0, sizeof(s2));
		printf("The Message from parent:");
		read(p[0], s2, 20);
		printf("s2: %s", s2);
	}	
	return 0;
}
