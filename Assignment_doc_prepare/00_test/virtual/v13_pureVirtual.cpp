#include<iostream>

class abstractClass{
public:
	virtual void boo(){}// = 0;
	virtual ~abstractClass() = 0;
	
};

class der: public abstractClass{
public:
	void boo(){
		std::cout << "der::boo()\n";
	}
};


abstractClass::~abstractClass(){
	std::cout << "abstractClass destructor\n";
}

int main()
{
	der obj;
	obj.boo();
	return 0;
}
