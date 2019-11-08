#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	int p[2];
	int q[2];
	pipe(q);
	pipe(p);
	char str1[20];
	char str2[20];
	memset(str1, 0, 20);
	memset(str2, 0, 20);
	if(fork()){
		//Parent process
		scanf("%s",&str1);
		write(p[1], str1, 20); 
		//sleep(1);
		
		read(q[0], str2, 20); 
		printf("%s",str2);
	}else{
		//Child process
		read(p[0], str2, 20); 
		printf("%s",str2);
		
		scanf("%s",&str1);
		write(q[1], str1, 20); 
		sleep(1);
	}
	return 0;
}
