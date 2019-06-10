#include<iostream>
#include<list>
#include<vector>

int main()
{
	std::list<std::string> liststr;
	liststr.push_back("first");
	liststr.push_back("sec");
	liststr.push_back("third");
	liststr.push_back("fourth");

	std::vector<std::string> v(liststr.begin(), liststr.end());

	for(std::string str: v)
		std::cout << str << std::endl;
	return 0;
}
