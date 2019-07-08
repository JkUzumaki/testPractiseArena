#include<iostream>
#include<string>

std::string swap(std::string a, std::string b)
{
	int len = a.size();
	std::string temp = a + b;
	std::cout << "Before swap " << temp << "\n";
	char temp1 = temp[len];
	temp[len] = temp[0];
	temp[0] = temp1;
	std::cout << "str temp: " << temp << std::endl;
	return temp;                       
}

int main()
{
	std::string str1 = "";
	std::string str2 = "";
	std::cout << "Enter the str1:\n";
	std::cin >> str1;
	std::cout << "Enter the str2:\n";
	std::cin >> str2;
	int len = 0;
	len = str1.size();
	std::cout << "The length of str1: " << len << "\n";
	len = str2.size();
	std::cout << "The length of str2: " << len << "\n";
	std::string str3 = str1 + str2;
	std::cout << "The str3 :" << str3 << "\n";
	str3 = swap(str1, str2);
	std::cout << "The str3 :" << str3 << "\n";
	return 0;
}
