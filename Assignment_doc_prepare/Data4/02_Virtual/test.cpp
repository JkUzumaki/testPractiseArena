#include<iostream>

void fun(int a=0){
	std::cout << "the value of a inside fun is " << a << std::endl;
}

int main()
{
	fun(9);
	return 0;
}
