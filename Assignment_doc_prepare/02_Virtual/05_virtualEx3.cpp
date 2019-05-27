#include<iostream>

class A{
public:
	virtual void f(){
		std::cout << "\nA::f()\n";
	}
};

class B: public A{
public:
	void f(){
		std::cout << "\nB::f()\n";
	}
};

class C: public B{
public:
	void f(){
		std::cout << "\nC::f()\n";
	}
};

class D:public C{};
int main()
{
	A* a = new A();
	B* b = new B();
	C* c = new C();

	a->f();
	b->f();
	c->f();

	((B*)c)->f();
	((A*)c)->f();
	((A*)b)->f();
	
	return 0;
}
