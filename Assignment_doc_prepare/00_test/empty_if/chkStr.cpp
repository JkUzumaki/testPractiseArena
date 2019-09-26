#include<iostream>
#include<string>

int main()
{
	std::string s1 = "if(1)";
	std::string s2 = "if";

	if(s1.find(s2) != std::string::npos){
		std::cout << "s1 is found in s2\n";
	}else{
		std::cout << "s1 is not found in s2\n";
	}
	
	return 0;
}
