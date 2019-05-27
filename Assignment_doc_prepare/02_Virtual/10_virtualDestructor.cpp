#include <iostream>
using namespace std;
class Base
{
public:
	Base() {
		cout << "Base Constructor \n" ;
	}
	~Base() {
		cout << "Base Destructor \n" ;
	}
};
class Derived : public Base
{
public:
	Derived(string s):str(s) {
		cout << "Derived Constructor \n" ;
	}
	~Derived() {
		cout << "Derived Destructor \n" ;
	}
private:
	string str;
};
int main()
{
	Base *pB = new Derived("derived");
	delete pB;
}

