#include <iostream>
#include <string>
#include <unistd.h> 

class Base
{
public:
	virtual void fn()
	{
		std::cout << "Base::fn\n";
	}
};

class Derived: public Base
{
public:
	void fn()
	{
		std::cout << "Derived::fn\n";
	}
};

int main()
{
	Base *bbptr = new Base;
	Derived *bdptr = new Derived;
	Derived *dptr;
	dptr = dynamic_cast<Derived*> (bbptr);
	if(dptr){
		std::cout << "dptr : " << dptr << "\n";
		dptr->fn();
	}else
		std::cout << "cannot create dynamic_cast\n";
}
