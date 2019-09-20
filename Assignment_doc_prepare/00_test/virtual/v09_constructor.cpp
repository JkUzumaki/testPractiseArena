#include<iostream>

class base{
public:
	base(){
		std::cout << "Base::const\n";
	}
	~base(){
		std::cout << "Base::destructor\n";
	}
};

class derived:public base{
public:
	derived(){
		std::cout << "derived::const\n";
	}
	~derived(){
		std::cout << "derived::dest\n";
	}
};

class derived1: public derived{
public:
	derived1(){
		std::cout << "derived1::const\n";
	}
	~derived1(){
		std::cout << "derived1::dest\n";
	}

};

int main()
{
	base *bptr = new derived1();
	delete bptr;
}
