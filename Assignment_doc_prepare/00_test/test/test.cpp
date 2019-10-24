#include<iostream>

class A
{
public:
	int a;
	int c;
	void fn(){}
};

class B:public virtual A
{
public:
	int b;
};

int main()
{
	A a;
	std::cout << "Size of A class object : " << sizeof(a) << std::endl;
	B b;
	std::cout << "Size of B class object : " << sizeof(b) << std::endl;
	return 0;
}
