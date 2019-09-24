#include<iostream>

class Base{
protected:
	int myInt;
public:
	Base(int n):myInt(n){
		std::cout << "Base Cnstr\n";
	}
	virtual void print() const = 0;
	virtual ~Base(){
		std::cout << "Base Destr\n";
	}
};

class Derived:public Base{
public:
	Derived(int n = 0):Base(n){
		str = new char[100];
		myInt = n;
		std::cout << "Derived Cnstr myInt\n";
	}
	
	void print() const {
		std::cout << "Derived print(): myInt = " << myInt << std::endl;
	}

	~Derived(){
		std::cout << "Derived Destr\n";
		delete [] str;
	}
private:
	char *str;
};

int main()
{
	Base *pB = new Derived(2010);
	pB->print();
	delete pB;
	return 0;
}
