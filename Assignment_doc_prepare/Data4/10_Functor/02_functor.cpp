#include<iostream>
#include<thread>
#include<unistd.h>

void foo(int a){
	sleep(1);
	std::cout << "The var is " << a << std::endl;
}

int main()
{
	
	auto f = [](int a, int b){
		std::cout << "a is " << a << ", b is " << b << std::endl;
		std::cout << "The sum of  a and b is " << a+b << std::endl;
	};
	std::thread t1(f,1, 5);
	std::thread t2(foo, 100);
	t1.join();
	t2.join();
	return 0;
}
