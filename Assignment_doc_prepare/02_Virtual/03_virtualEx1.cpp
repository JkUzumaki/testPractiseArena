#include<iostream>

class A{
public:
	void f(){
		std::cout << "A::f()" << std::endl;
	}
};

class B: public A{
public:
	void f(){
		std::cout << "B::f()\n";
	}
};

class C: public B{
public:
	void f(){
		std::cout << "C::f()\n";
	}
};

class D:public C{
public:
	// 
};

int main()
{
	A* a = new A();
	B* b = new B();
	C* c = new C();
	D* d = new D();

	a->f();
	b->f();
	c->f();
	d->f();

	((B*)c)->f();
	((A*)c)->f();
	((A*)b)->f();

	return 0;
}
