#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int p[2];
	pipe(p);
	int fd = 0;
	//fd = open("test", O_CREAT, 0777);
	char s1[20];
	char s2[20];
	if(fork() == 0){
		memset(s1, 0, sizeof(s1));
		printf("The Message to child:\n");
		scanf("%s",&s1);
		write(p[1], s1, 20);
		//sleep(1);
		
	}else{
		memset(s2, 0, sizeof(s2));
		read(p[0], s2, 20);
		printf("The Message from parent:\n");
		printf("data: %s\n", s2);
	}
	return 0;
}
