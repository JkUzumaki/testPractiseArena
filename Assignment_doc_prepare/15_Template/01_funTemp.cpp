#include<iostream>

template <typename Z>
Z mySum(Z a, Z b)
{
	return a+b;
}

int main()
{
	std::cout << mySum(3,7) << std::endl;
	std::cout << mySum(1.0,2.5) << std::endl;
	std::cout << mySum('a', '.') << std::endl;
	return 0;
}
