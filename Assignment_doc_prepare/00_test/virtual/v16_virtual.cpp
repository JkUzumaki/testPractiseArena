#include<iostream>

class Base{
public:
	virtual void methodA()
	{
		std::cout << "Base::void MethodA()\n";
	}
	virtual void methodA(int a)
	{
		std::cout << "Base::void MethodA(int a)\n";
	}	
};

class Derived:public Base{
public:
	void methodA(){
		std::cout << "Derived::void MethodA\n";
	}
	void methodA(int a){
		std::cout << "Derived::void MethodA(int a)\n";
	}
};

int main()
{
	Derived d;
	d.methodA();
	d.methodA(40);
	return 0;
}
