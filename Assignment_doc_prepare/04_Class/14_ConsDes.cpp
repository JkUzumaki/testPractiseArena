#include<iostream>

class A
{
public:
	A()
	{
		std::cout << "A Const\n";
	}
	~A()
	{
		std::cout << "A Dest\n";
	}
};

class B:public A
{
public:
	B()
	{std::cout << "B Const\n";}
	~B()
	{std::cout << "B Dest\n";}
};


class C:public B
{
public:
	C()
	{std::cout << "C Const\n";}
	~C()
	{std::cout << "C Dest\n";}
};

int main()
{
	C a;
}
