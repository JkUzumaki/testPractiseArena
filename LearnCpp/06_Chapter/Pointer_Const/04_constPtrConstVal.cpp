#include<iostream>

int main()
{
	int v = 5;
	const int *const ptr = &v;// Mention the value is const and pointer pointing to is also const
	std::cout << *ptr << std::endl;
	//v = 10;
	*ptr = 10;
	std::cout << *ptr << std::endl;
}
