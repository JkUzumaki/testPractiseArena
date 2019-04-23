#include<iostream>
#include<cstdio>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

using namespace std;

int main()
{
	int sem1, sem2, sem3;
	key_t ipc_key = 2;
	//ipc_key = ftok(".", 'S');
//SEM1
	if((sem1 = semget(ipc_key, 3, IPC_CREAT|0666)) == -1){
		cerr << "semget: IPC_CREAT | 0666" << endl;
	}
	cout << "sem1 id : " << sem1 << endl;
//SEM2	
//~~~~
// This sem creation will fail, as a sem is already created with ipc_key
// Here we are setting the IPC_EXCL and using the same ipc_key will cause 
// Semaphore to fail.
	if((sem2 = semget(ipc_key, 3, IPC_CREAT|IPC_EXCL|0666)) == -1){
		cerr << "semget: IPC_CREAT | 0666" << endl;
	}
	cout << "sem2 id : " << sem2 << endl;
//SEM3
// The semaphore created here will be provate to this process
	if((sem3 = semget(IPC_PRIVATE, 3,0666)) == -1){
		cerr << "semget: IPC_PRIVATE | 0666" << endl;
	}
	cout << "sem3 id : " << sem3 << endl;

	return 0;
}
