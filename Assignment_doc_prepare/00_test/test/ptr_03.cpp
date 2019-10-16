#include<iostream>

int main()
{
	int a[10];
	a[0] = 11;
	int *pa[10];
	for(int i = 0; i < 10; i++){
		pa[i] = &(*(a+i));
		//a[i] = i*10;
		*(a+i) = i * 10;//array can be written like this
				// what is this ?
	}
	std::cout << *pa << std::endl;
	std::cout << *pa[0] << std::endl;
	std::cout << *pa[9] << std::endl;
	std::cout << a[9] << std::endl;
	
	return 0;
}
