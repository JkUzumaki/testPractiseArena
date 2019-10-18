#include<iostream>

class A{
public:
	//int *a;
	int b;
	A(){
	   //a = &b;
	}
	void set(int v){
		b = v;
	}
	void get(){
		std::cout << "a: " << b << std::endl;
	}
};

int main()
{
	A a, b;
	std::cout << "Value in object a\n";
	a.set(10);
	a.get();
	std::cout << "object b is assigned with a\n";
	b = a;
	std::cout << "Value in object b\n";
	b.get();
	std::cout << "Modifying the content of a\n";
	a.set(5);
	a.get();
	std::cout << "Value in object b\n";
	b.get();
	return 0;
}
