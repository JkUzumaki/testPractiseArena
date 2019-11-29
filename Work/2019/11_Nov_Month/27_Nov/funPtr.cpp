#include<iostream>

void fn()
{
	std::cout << "Inside the function fn\n";
}

int  main()
{
	void (*fptr) (void)= &fn;
	fptr();
	return 0;
}
