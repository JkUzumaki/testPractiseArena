#include<iostream>
#include <memory>
#include <iostream>
#include <string>

int main()
{
	int data= 99;
	std::unique_ptr<int> uPtr = new int(data);//NULL;// = ptr;
	if(uPtr == nullptr)
		std::cout << "uPtr is a nullptr\n";
	else
		std::cout << "uPtr is not a nullptr\n";
	return 0;
}
