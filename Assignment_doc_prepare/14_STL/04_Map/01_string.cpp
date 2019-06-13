#include<map>
#include<string>
#include<iterator>
#include<iostream>

int main()
{
	std::map<std::string, int> map;
	map.insert(std::make_pair("earth", 1));
	map.insert(std::make_pair("moon", 2));
	map["sun"] = 3;
	map["earth"] = 4;

	std::map<std::string, int>:: iterator it = map.begin();
	while(it != map.end()){
		std::cout << it->first << " " << it->second << "\n";
		it++;
	}
	if(map.insert(std::make_pair("earth", 1)).second == false)
    	{
        	std::cout<<"Element key 'earth' not inserted because already existed"<<std::endl;
    	}
    // Searching element in std::map by key.
    if(map.find("sun") != map.end())
        std::cout<<"word 'sun' found"<<std::endl;
    if(map.find("mars") == map.end())
        std::cout<<"word 'mars' not found"<<std::endl;
    return 0;
}
