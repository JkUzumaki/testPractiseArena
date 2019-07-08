#include<iostream>
#include<sstream>

int main()
{
	std::stringstream ss("23,4,56");
	char ch;
	int a, b, c;
	ss >> a >> ch >> b >> ch >> c;
	std::cout << "a : " << a << "\n";	
	std::cout << "b : " << b << "\n";	
	std::cout << "c : " << c << "\n";	
	std::cout << "ch : " << ch << "\n";	
}
