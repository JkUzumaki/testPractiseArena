#include <iostream>
using namespace std;

class Base
{
  public:
  ~Base() {cout << "Base Destructor"; }
};

class Derived:public Base
{
  public:
  ~Derived() { cout<< "Derived Destructor"; }
};

int main()
{
  Base* b = new Derived;
  delete b;
  return 0;
}
