#include<iostream>

const int x = 7;

int main()
{
	std::cout << x;
	int x[x];
	int sz = sizeof(x)/sizeof(x[0]);
	std::cout << "\nsz: " << sz << std::endl;
	return 0;
}
