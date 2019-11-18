#include<iostream>
#include<array>

int main()
{
	std::array<int, 5> a = {1,2,3,5,4};
	std::cout << "\nSize of array is " << a.size();
	auto pos = a.begin();
	std::cout << std::endl;
	while(pos != a.end())
		std::cout << *pos++ << "\t";
	std::cout << "\n";
	return 0;
}
