#include<iostream>

class Base{
public:
	double a, b;
	virtual void result(){
		std::cout << "Base::result\n";
	}
};

class Test:public Base{
public:
	int c, d;
	void result(){
		std::cout << "Test::result\n";
	}
};

int main(){
	Base *obj1 = new Test();
	Base *obj2 = new Base();
	Test *ptr;// = new Base();
/*	ptr = dynamic_cast<Test*>(obj1);
	if(ptr){
		std::cout << "ptr: " << ptr << std::endl;
	}
	ptr->result();
*/

	Base b;
	ptr = &b;
	ptr->result();
	return 0;
}
