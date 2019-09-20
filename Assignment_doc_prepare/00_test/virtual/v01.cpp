#include<iostream>

class A{
public:
	virtual void foo(){
		std::cout << "A::foo\n";
	}

	virtual void foo1(){
		std::cout << "A::foo1\n";
	}
};

class B: public A{
public:
	void foo(){
		std::cout << "B::foo\n";
	}

	void foo1(){
		std::cout << "B::foo1\n";
	}
};

int main()
{
	B b;
	A *a = &b;
	a->foo();
	a->foo1();
	return 0;
}
