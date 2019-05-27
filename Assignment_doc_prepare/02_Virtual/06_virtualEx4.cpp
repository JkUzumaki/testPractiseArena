#include<iostream>

class Base{
public:
	void f();
	virtual void vf();
};

class Derived: public Base{
public:
	void f();
	void vf();
};

void Base::f(){
	std::cout << "Base f()\n";
}

void Base::vf(){
	std::cout << "Base vf()\n";
}

void Derived::f(){
	std::cout << "Derived f()\n";
}

void Derived::vf(){
	std::cout << "Derived vf()\n";
}

int main()
{
	Base b1;
	Derived d1;
	b1.f();
	b1.vf();
	d1.f();
	d1.vf();

	Derived d2;
	Base* bp = &d2;
	bp->f();
	bp->vf();

	return 0;
}
