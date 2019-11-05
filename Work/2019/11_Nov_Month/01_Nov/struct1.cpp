#include<iostream>

class base
{
public:
	int a;
	virtual int foo()
	{
		std::cout << "base::foo\n";	
	}
	int getB(){
		return b;
	}
	void setB(int val){
		b = val;
	}
private:
	int b;
};

class child:public base
{
public:
	int foo()
	{
		std::cout << "child::foo\n";
	}
};

int main()
{
	base *obj;
	child cObj;
	obj = &cObj;
	obj->foo();
}
