#include<list>
#include<string>
#include<algorithm>
#include<iostream>

int main()
{
	std::list<std::string> listStr = {"is", "of", "the", "Hi", "Hello", "from"};

	std::list<std::string>::iterator it;

	it = std::find(listStr.begin(), listStr.end(), "the");
	if(it != listStr.end())
		std::cout << "'the' exists in list" << std::endl;
	else
		std::cout << "'the' does not exists in list" << std::endl;

	return 0;	
}
