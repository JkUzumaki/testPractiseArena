#include <iostream>

class Base 
{
public:
	void f() {std::cout << "Base::f()\n";}
	virtual	void vf(){std::cout << "Base::vf()\n";};
};

class Derived: public Base
{
public:
	void f() {std::cout <<"Derived::f()\n";}
	void vf(){std::cout <<"Derived::vf()\n";};
};

int main()
{
	Base b;
	Base *pb = &b;
	Derived d;
	Derived *pd = &d;
	Base *pbd = &d;
	b.f();
	d.f();
	pb->f();
	pd->f();
	pbd->f();
	pbd->vf();

	return 0;
}
