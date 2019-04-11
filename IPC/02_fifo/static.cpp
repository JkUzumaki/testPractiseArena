#include<iostream>
using namespace std;

void foo(int a)
{
	cout << a << endl;
	a++;
}

int main()
{
	static int var = 10;
	cout << var << endl;
	foo(var);
	cout << var << endl;
	
}
