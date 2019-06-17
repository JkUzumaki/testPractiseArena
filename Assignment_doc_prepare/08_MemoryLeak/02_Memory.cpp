#include<iostream>

int main()
{
	int value = 5;
	int* ptr = new int;
	delete ptr;
	ptr = &value;
	std::cout << "ptr " << ptr << " *ptr " << *ptr << std::endl;
	return 0;
}
