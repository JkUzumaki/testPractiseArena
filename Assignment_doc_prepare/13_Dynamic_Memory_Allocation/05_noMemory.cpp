#include<iostream>

int main()
{
	int *ptr = NULL;
	ptr = new (std::nothrow) int(1000000000000);
	if(ptr == NULL)
		std::cout << "Memory is not available\n";
}
