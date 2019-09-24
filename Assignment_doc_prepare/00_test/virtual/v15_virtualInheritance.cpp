#include<iostream>

class Base{
public:
	Base(){
		std::cout << "Base\n";
	}
};

class D1:virtual public Base{
public:
	D1(){
		std::cout << "D1\n";
	}
};

class D2:virtual public Base{
public:
	D2(){
		std::cout << "D2\n";
	}
};

class D3: public Base{
public:
	D3(){
		std::cout << "D3\n";
	}
};


class D4: public Base{
public:
	D4(){
		std::cout << "D4\n";
	}
};

class DDD: public D1, D2, D3, D4{};

int main()
{
	DDD d;
	return 0;
}
