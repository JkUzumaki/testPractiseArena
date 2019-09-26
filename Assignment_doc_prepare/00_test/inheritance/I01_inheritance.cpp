#include<iostream>

class A{
public:
	A(int n = 1):ia(n){
		std::cout << "A() "<< ia << "\n";
	}
	~A(){
		std::cout << "~A() " << ia << "\n";
	}
protected:
	int ia;
};

class B:public A{
public:
	B(int n):a1(ia+10), a2(n){
		std::cout << "B() " << ia << "\n";
	}
	~B(){
		std::cout << "~B()" << ia-- << std::endl;
	}
private:
	A a2;
	A a1;
};

int main(){
	{
		B b(20);
	}
	return 0;
}
