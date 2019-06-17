#include<iostream>

int main()
{
	int *ptr = nullptr;
	std::cout << "Before allocation\n";
	if(!ptr){
	std::cout << "allocate memeory\n";	
	ptr = new int;
	}
	if(ptr){
		std::cout << "The memory is not empty\n";
		delete ptr;
		std::cout << "The memory is deleted\n";
		
	}
	std::cout << "Before the end of the program\n";
	return 0;
}
