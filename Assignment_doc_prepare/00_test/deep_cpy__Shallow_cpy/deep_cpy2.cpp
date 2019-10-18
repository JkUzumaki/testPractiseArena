#include<iostream>
	
class ex
{
	int a, b;
public:
	ex(int x, int y){
		a = x; b = y;
		std::cout << "In constructor\n";
	}
	/*
	ex(const ex& o){
		a = o.a;
		b = o.b;
	}
	*/
	void set(int x, int y){
		a = x; b = y;
	}
	void display(){
		std::cout << "a: " << a << " b: " << b << std::endl;
	}
};

int main()
{
	ex a1(10, 20);
	ex a2 = a1;
	a1.display();
	std::cout << "Modify the a1 object\n";
	a1.set(30, 40);
	a1.display();
	a2.display();
	std::cout << "\n";
	return 0;
}
