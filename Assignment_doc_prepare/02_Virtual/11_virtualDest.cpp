#include <iostream>

using namespace std;

class Base{
protected:
	int myInt;

public:
	Base(int n):myInt(n){
		cout << "Base Ctor\n";
	}
	virtual void print() const = 0;
	virtual ~Base(){
		cout << "Base Dtor" << endl;
	}
};

class Derived: public Base {
public:	
	Derived(int n = 0):Base(n)  {
		str = new char[100];
		myInt = n;				
		cout << "Derived Ctor myInt" << endl;
	}
	void print()const{
		cout << "Derived print(): myInt = "<< myInt << endl;
	}

	~Derived(){
		cout << "Derived Dtor" << endl;
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
