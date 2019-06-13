#include<iostream>
#include<map>

int main()
{
	std::multimap<std::string, int> map;
	/*
	map["A"] = 1;
	map["B"] = 2;
	map["C"] = 3;
	*/
	map.insert(std::make_pair("A", 1));
	map.insert(std::make_pair("B", 2));
	map.insert(std::make_pair("C", 3));
	map.insert(std::make_pair("A", 10));
	//map["A"] = 10;
	std::multimap<std::string, int>::iterator it;
	it = map.begin();
	while(it != map.end()){
		std::cout << "key " << it->first << ", value " << it->second << std::endl;
		it++; 
	}
	return 0;
}
