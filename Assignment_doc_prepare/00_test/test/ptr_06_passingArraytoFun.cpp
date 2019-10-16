#include<iostream>

void fun(int *a);

int main()
{
	int a[10];
	int *pa = a;
	for(int i = 0; i < 10; i++){
		a[i] = i * 10;
	}
	std::cout << a << std::endl;
	if(a == &a[0]){
		std::cout << "Both address are SAME\n";
	}
	fun(pa);
	std::cout << "\n";
}

void fun(int *a){
	for(int i = 0; i < 10; i++){
		std::cout << *(a+i) << " ";
	}
}
