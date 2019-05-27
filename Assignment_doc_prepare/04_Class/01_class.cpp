#include<iostream>
#include<string>
class Data
{
public:
	std::string name;
	void printName(){
		std::cout << "Name is " << name << std::endl;
	}
};

int main()
{
	Data obj;
	obj.name = "Kumar";
	obj.printName();
	return 0;
}
