#include<iostream>
#include<vector>

std::vector<int> v(5, 20);

int main()
{
	for(int x: v)
		std::cout << x << " ";
	std::cout << std::endl;
}
