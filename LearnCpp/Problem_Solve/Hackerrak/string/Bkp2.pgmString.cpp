#include<iostream>
#include<string>

void swap(std::string &a, std::string &b)
{
	int len1 = a.size();
	int len2 = b.size();
	std::string str = a + b;
	char temp = a[0];
	a[0] = b[0];
	b[0] = temp;
	std::cout << len1 << " " << len2 << std::endl;
	std::cout << str << std::endl;
}

int main()
{
	std::string str1 = "";
	std::string str2 = "";
	std::cin >> str1;
	std::cin >> str2;
	
	swap(str1, str2);
	std::cout << str1 << " " << str2 << std::endl;
	return 0;
}
