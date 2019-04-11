//shared memory write
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define BUF_SIZE 1024
#define SHM_KEY 0x1234

struct shmseg{											// struct shmseg 
	int cnt;
	int complete;
	char buf[BUF_SIZE];
};

int fill_buffer(char* bufptr, int size);

int main(int argc, char *argv[])
{
	int shmid, numtimes;
	struct shmseg *shmp;
	char *bufptr;
	int spaceavailable;
	shmid = shmget(SHM_KEY, sizeof(struct shmseg), 0777|IPC_CREAT);				// >>	Creating the shared memory
	if(shmid == -1){									// >>	Check if shared memory is created
		perror("Shared memory not created\n");
		return 1;
	}

	shmp = shmat(shmid, NULL, 0);								// >>	Attaching the shared memory
	if(shmp == (void*) -1){
		perror("Shared memory attach\n");
		return 1;
	}
	
	bufptr = shmp->buf;									// >>	Assigning the shmp->buf to bufptr
	spaceavailable = BUF_SIZE;								
	for(numtimes = 0; numtimes < 5; numtimes++){				
		shmp->cnt = fill_buffer(bufptr, spaceavailable);				
		shmp->complete = 0;								// Filling struct member
		printf("Writing process: Shared Memory Write: Wrote %d bytes\n", shmp->cnt);	
		bufptr = shmp->buf;								// Filling struct member
		spaceavailable = BUF_SIZE;							// 
		sleep(3);									// 
	}
	
	printf("Writing process: Wrote %d times\n", numtimes);					// 
	shmp->complete = 1;

	if(shmdt(shmp) == -1){									// >>	Detach the shared memory
		perror("shmdt");
		return 1;
	}

	if(shmctl(shmid, IPC_RMID, 0) == -1){							// >>	Marks the segment to be destroyed after last 
												//	process is destroyed
		perror("shmctl");
		return 1;
	}
	
	printf("Writing process: Complete\n");							
	return 0;
}

int fill_buffer(char* bufptr, int size)
{
	static char ch = 'A';
	int filled_count;

	memset(bufptr, ch, size-1);								// Copying data to bufptr
	bufptr[size-1] = '\0';
	if(ch > 122)
		ch = 65;
	if( (ch >= 65) && (ch <= 122)){
		if( (ch >= 91) && (ch <= 96)){
			ch = 65;
		}
	}
	filled_count = strlen(bufptr);								
	ch++;
	return filled_count;
}
