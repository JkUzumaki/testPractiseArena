#include<iostream>

int main()
{
	int val = 5;
	int *ptr = &val;
	*ptr = 10;
	std::cout << "val " << val << std::endl;
	return 0;
}
