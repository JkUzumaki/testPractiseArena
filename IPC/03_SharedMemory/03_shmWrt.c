#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define BUF_SIZE 100
#define SHM_KEY 0x1234

struct shmseg
{
	int cnt;
	int complete;
	char buf[BUF_SIZE];
};

int main(int argc, char* argv[])
{
	int shmid, numtimes;
	struct shmseg *shmp;
	char* bufptr;
	int spaceavailable;
	int count = 0;
	shmid = shmget(SHM_KEY, sizeof(struct shmseg), 0777|IPC_CREAT);
	if(shmid == -1){
		perror("Shared memory not created\n");
		return 1;
	}

	shmp = shmat(shmid, NULL, 0);
	if(shmp == (void*) -1){
		perror("Shared memory attach\n");
		return 1;
	}
	bufptr = shmp->buf;
	
	spaceavailable = BUF_SIZE;
	while(1){
		shmp->
	}
}
