#include<iostream>

int main()
{
	int *ptr;
	int **pptr;
	int ***ppptr;
	int val = 5;
	ptr = &val;
	pptr = &ptr;
	ppptr = &pptr;

	std::cout << "ptr : " << ptr << std::endl;
	std::cout << "pptr : " << pptr << std::endl;
	std::cout << "ppptr : " << ppptr << std::endl;
	
	std::cout << "*ptr : " << *ptr << std::endl;
	std::cout << "**pptr : " << **pptr << std::endl;
	std::cout << "***ppptr : " << ***ppptr << std::endl;
	
	return 0;
}
