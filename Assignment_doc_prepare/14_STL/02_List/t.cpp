#include<iostream>
#include<vector>
#include<iterator>

int main()
{
	std::vector<int> v = {10, 20, 30, 40};
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}
