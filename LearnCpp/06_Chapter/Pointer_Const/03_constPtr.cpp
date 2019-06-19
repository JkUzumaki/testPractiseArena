#include<iostream>

int main()
{
	int val = 5;
	int *const ptr = &val;
//	val = val + 9;
	*ptr += 10;
	std::cout << *ptr << std::endl;	
}
