#include <iostream>
using namespace std;
class X
{
    public:
    int i;
	static void f()
    {
        // statement
	i = 90;
	cout << "inside f() call\n" << i << endl;
    }
};

int main()
{
    //X::f();   // calling member function directly with class name
	X x;
	x.f();
}
