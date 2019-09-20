#include<iostream>
using namespace std;

class Base{
public:
	char *name;
	//virtual 
	void display(){
		std::cout << name << std::endl;
	}
};

class Derived: public Base{
public:
	char *name;
	void display(){
		std::cout << name << ", " << Base::name << std::endl;
	}
};

int main(){
	Derived d;
	d.name = "Derived Class";
	d.Base::name = "Base Class";
	
	Derived *dptr = &d;
	
	Base* bptr = dptr;

	bptr->display();
	return 0;
}

/*
	Rule 1: Always see the content of the ptr is there is a virtual function being used.
	Rule 2: Always see the type of the ptr, is there is no virtual function being used.
*/
