#include<iostream>

int main()
{
	int *ptr = new int;
	*ptr = 7;
	std::cout << *ptr << std::endl;
	std::cout << "The ptr address " << ptr << std::endl;
	delete ptr;
	
	std::cout << "After double delete\n";
	std::cout << "The ptr address " << ptr << std::endl;
	std::cout << *ptr << std::endl;
	
	return 0;	
}
