#include<iostream>

class Base
{
public:
	virtual void fn(){
		std::cout << "Base::fn\n";
	}
};

class Derived: public Base
{
public:
	void fn(){
		std::cout << "Derived::fn\n";
	}
};

int main()
{
/*

	Base *b;
	Derived d;
	b = &d;
	b->fn();
*/

	Derived *d;
	Base b;
	d = dynamic_cast<Derived*>(&b);
	d->fn();
	return 0;
}
