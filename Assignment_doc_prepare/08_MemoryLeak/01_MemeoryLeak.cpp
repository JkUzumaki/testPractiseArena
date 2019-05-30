#include<iostream>

using namespace std;
	
void function_memoryLeak()
{
	int *ptr = new int [10];	// 10*4 40 bytes of memory is dynamically allocated
	//delete ptr;	
}
int main()
{
	function_memoryLeak();
	return 0;
}
