#include<iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base Constructor\n";
	}
	~Base()
	{
		std::cout << "Base Destructor\n";
	}
	int fun()
	{
		std::cout << "Base::fun\n";
	}
};

class Derived: public Base
{
public:
	Derived()
	{
		std::cout << "Derived Constructor\n";
	}
	~Derived()
	{
		std::cout << "Derived Destructor\n";
	}
	int fun1()
	{
		std::cout << "Derived::fun1\n";
	}
};

int main()
{
	Derived d;
	d.fun();
	d.fun1();
	return 0;
}
