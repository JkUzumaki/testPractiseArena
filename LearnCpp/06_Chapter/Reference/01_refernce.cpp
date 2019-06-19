#include<iostream>

int main()
{
	const int value = 5;
	const int &ref = value;
	std::cout << ref << std::endl;
	std::cout << "ADDRESS of ref " << &ref << std::endl;
	std::cout << "ADDRESS of value "<< &value << std::endl;
}
