//shm_read
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

#define BUF_SIZE 1024
#define SHM_KEY 0x1234		// Key value

struct shmseg{
	int cnt;		// Data length
	int complete;		// Flag variable
	char buf[BUF_SIZE];	// Data in string format
};

int main(int argc, char *argv[]){
	int shmid;
	struct shmseg *shmp;
	shmid = shmget(SHM_KEY, sizeof(struct shmseg), 0777|IPC_CREAT);				// Creating the shared memory
	if(shmid == -1){
		perror("Shared memory error");
		return 1;
	}

	shmp = shmat(shmid, NULL, 0);								// Attach of shared memory
	if(shmp == (void *) -1){
		perror("Shared memory attach\n");
		return 1;
	}

	while(shmp->complete != 1){								// Checks the structure member value
		printf("Segment contains: \n\"%s\"\n", shmp->buf);				// shmp->buf 
		if(shmp->cnt == -1){								
			perror("read");								
			return 1;
		}
		printf("Reading process: Shared memory: read %d bytes\n", shmp->cnt);		
		sleep(3);
	}
	printf("Reading Process: Reading Done, Detaching Shared Memory\n");
	if(shmdt(shmp) == -1){									// Detach of shared memory
		perror("shmdt");
		return 1;
	}
	printf("Reading Process: Complete\n");
	return 0;
}
