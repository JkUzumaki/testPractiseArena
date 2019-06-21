#include<iostream>

class A
{
int a;
public:
//A(){a =0;}
A(int d){a = d;}
int get()
{
	return a;
}
};

int main()
{
	A o;
	std::cout << "The value of a is " << o.get() << std::endl;
}
