#include<iostream>
using namespace std;
int main()
{
        int* p = new int(101);
        cout << "Address of p " << p << endl;
        cout << "Value at p " << *p << endl;
        delete p;
        int* q = new int(98);
	*p= 90;
	cout << "Address of p " << p << endl;
        cout << "Value at p " << *p << endl; 
	delete q;
	int b = 10;
	int *a = &b;
	cout << "a address is " << a << endl;
	cout << "a value is " << *a << endl;
	//delete a;
	cout << "a address is " << a << endl;
	cout << "a value is " << *a << endl;

	return 0;
}
/*
1. Delete a pointer which is not allocated memory dynamically is not recommended
2. Deleting a dynamic memory dosen't mean the memory is not deleted anything, it just returns the memory to the OS as it has no 
*/
