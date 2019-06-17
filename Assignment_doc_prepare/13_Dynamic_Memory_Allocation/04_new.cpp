#include<iostream>

int main()
{
	int* ptr = new int;
	int* optr = ptr;
	*ptr = 190;
	std::cout << "The *ptr " << *ptr << std::endl;
	std::cout << "The ptr " << ptr << std::endl;
	std::cout << "The *optr " << *optr << std::endl;
	std::cout << "The optr " << optr << std::endl;
	delete ptr;
	ptr = nullptr;
	std::cout << "The *ptr " << *ptr << std::endl;
	std::cout << "The ptr " << ptr << std::endl;
	std::cout << "The *optr " << *optr << std::endl;
	std::cout << "The optr " << optr << std::endl;


}
