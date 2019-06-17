#include<iostream>

int main()
{
	int* ptr = nullptr;
	ptr = new int[1000000000];
	if(ptr == NULL)
		std::cout << "Memory is not available\n";
	else
		std::cout << "Memeory is allocated\n";
	if(ptr != NULL)
		delete ptr;
	return 0;
}
