#include <iostream>

using namespace std;
// Array representation with the ptr
int main () 
{
	int arr[3] = {1,2,3};
	
	cout << &arr << endl;
	int* a = &arr;
	cout << &arr+1 << endl;
	int* b = (&arr+1);
	cout << b-a << endl;
	return 0;

}
