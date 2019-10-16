#include<iostream>

int main()
{
	int *pa;
	int a[10];
	pa = a;
	std::cout << "pa: " << pa << std::endl;
	std::cout << "a: " << a << std::endl;
	pa++;
	std::cout << "After incrementing\n";
	std::cout << "pa: " << pa << std::endl;
	std::cout << "&a[1] " << &a[1] << std::endl;
}
