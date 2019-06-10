#include<iostream>
#include<list>
#include<string>
#include<iterator>
#include<algorithm>

int main()
{
	std::list<std::string> listStr = {"First", "sec", "third", "fourth", "fifth", "sixth"};
	
	std::list<std::string>::iterator it = listStr.begin();

	std::advance(it, 2);

	std::cout << "3rd element = " << *it << std::endl;

	auto it1 = std::next(listStr.begin(), 5);
	std::cout << "5th element = " << *it1 << std::endl;
	return 0;
}
