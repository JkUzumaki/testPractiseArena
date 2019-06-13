#include<iostream>
using namespace std;
int main()
{
	int *ptr = NULL;
	delete ptr;
	*ptr = 10;
}
