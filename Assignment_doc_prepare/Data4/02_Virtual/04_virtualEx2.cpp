#include<iostream>

class Base{
public:
	char* name;
virtual	void display(){
		std::cout << "name " << name << std::endl;
	}
};

class Derived:public Base
{
public:
	char* name;
	void display(){
		std::cout << "name: " << name << ", " << Base::name << "\n";
	}
};

int main()
{
	Derived d;
	d.name = "Derived Class";
	d.Base::name = "Base Class";

	Derived* dptr = &d;
	
	Base* bptr = &d;

	bptr->display();
	return 0;
}
