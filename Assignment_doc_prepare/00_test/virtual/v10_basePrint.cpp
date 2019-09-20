#include <iostream>

using namespace std;

struct Base
{
  Base() { cout << "Base" << endl; }
};

struct d1 : virtual public Base {d1(){cout << "d1" << endl;}};
struct d2 : virtual public Base {d2(){cout << "d2" << endl;}};
struct d3 : public Base {d3(){cout << "d3" << endl;}};
struct d4 : public Base {d4(){cout << "d4" << endl;}};
struct ddd : public d1, public d2, public d3, public d4
{ };

int main(int argc, char** argv) 
{ 
	ddd d;
	return 0; 
}
