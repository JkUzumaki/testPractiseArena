#include<iostream>

struct Student
{
	int Age;
	std::string fName;
	std::string lName;
	int Standard;
};

int main()
{
	Student s;
	std::cin >> s.Age;
	std::cin >> s.fName;
	std::cin >> s.lName;
	std::cin >> s.Standard;
	
	std::cout << s.Age << " " << s.fName << " " << s.lName << " " << s.Standard << std::endl;
	
}
