#include<iostream>

extern int val2;
static void fun1()
{
	val2 +=1;
	std::cout << "Value 2: " << val2 << std::endl;
}
