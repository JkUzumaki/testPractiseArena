#include<iostream>

class A{
public:	A()
	{
		std::cout << "A::constructor\n";
	}
	~A(){
		std::cout << "A::destructor\n";
	}
};

class B: public A{
public:
	B()
	{
		std::cout << "B::constructor\n";
	}
	~B(){
		std::cout << "B::destructor\n";
	}
	
};

int main()
{
	B b;
	return 0;
}
