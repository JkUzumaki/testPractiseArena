#include<iostream>

struct test{
	int value1;
	int value2;
	char array[10];
}t;

int main()
{
	struct test *ptr = &t;
	struct test *ptr1 = ptr+1;
	int val = (char*) ptr1 - (char*) ptr;
	//int val = (int*) ptr1 - (int*) ptr;
	//int val =  ptr1 -  ptr;
	int abc = 0x6011b4;
	//std::cout << "ptr1 " <<ptr1 << std::endl;
	std::cout << "ptr " << ptr << std::endl;
	//std::cout << "*ptr1 " << *ptr1 << std::endl;
	//std::cout << "*ptr " << *ptr << std::endl;
	//char a =  ptr1;
	std::cout << "(char*) ptr1 " << (char*)ptr1 << std::endl;
	//std::cout << "(char*) ptr " << (char*) ptr << std::endl;
	std::cout << "\n\nVALUE : " << val << std::endl;
	return 0;
}
