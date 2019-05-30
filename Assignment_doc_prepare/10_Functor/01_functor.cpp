#include<iostream>
#include<thread>
int main()
{
	
	auto f = [](int a, int b){
		std::cout << "a is " << a << ", b is " << b << std::endl;
		std::cout << "The sum of  a and b is " << a+b << std::endl;
	};
	std::thread t1(f,1, 5);
	
	t1.join();
	return 0;
}
