#include <set>
#include <iostream>
#include <set>
#include <string>

int main()
{
	std::set<std::string> set;
	
	set.insert("first");
	set.insert("second");
	set.insert("third");
	set.insert("first");

	std::cout << "Set size = " << set.size() << std::endl;

	for(std::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	return 0;
}
