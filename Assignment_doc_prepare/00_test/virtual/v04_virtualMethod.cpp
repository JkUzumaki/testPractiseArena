#include<iostream>

class A{
public:
	virtual void f(){
		std::cout << "A::f()\n";
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

int main()
{
	A *a = new A;
	B *b = new B;
	C *c = new C;

	a->f();	//A::f()
	b->f();	//B::f()
	c->f(); //C::f()
	
	((B*)c)->f();	// C::f()
	((A*)c)->f();	// C::f()
	((A*)b)->f();	// B::f()

	return 0;
}
