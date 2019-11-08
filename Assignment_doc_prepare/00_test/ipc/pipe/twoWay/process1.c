#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int p1[2];
	int p2[2];

	pipe(p1);
	pipe(p2);
	
	char str1[20];
	char str2[20];

	if(fork()){
		//Parent process
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
		//Write
		printf("Parent: Message to child\n");
		gets(str1);
		write(p1[1], str1, 20);//Write in 1 index
		//Read
		read(p2[0],str2, 20);//Read in 0 index
		printf("Parent: The Message from child\n");
		printf("%s\n", str2);
		sleep(1);
	}else{
		//Child Process
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
		//Read
		read(p1[0], str2, 20);	
		printf("Child: The Message from parent\n");
		printf("data: %s\n", str2);
		//Write
		printf("Child: Message to parent\n");
		gets(str2);
		write(p2[1], str2, 20);
		//sleep(1);
	}
	printf("\n");
	return 0;
}
