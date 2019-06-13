#include<set>
#include<iostream>
#include<string>
#include<bits/stdc++.h>
int main()
{
	std::unordered_set<std::string> strSet;
	
	strSet.insert("c");
	strSet.insert("++");
	strSet.insert("is");
	strSet.insert("fast");
	strSet.insert("yes");

	std::string key = "slow";
	
	if(strSet.find(key) == strSet.end())
		std::cout << key << " not found in set\n";
	else	
		std::cout << key << " found in set\n";
	std::cout << "\nAll elements : \n";
	std::unordered_set<std::string> :: iterator itr;
	for(itr = strSet.begin(); itr != strSet.end(); itr++)
		std::cout << *itr << "\n";
}
