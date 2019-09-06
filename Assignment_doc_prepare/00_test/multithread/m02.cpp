#include <iostream>
#include <chrono>
#include <thread>

void fn1()
{
	int i = 0;
	while(i != 100000000){
		i++;
	}
	std::cout << "Hi 1\n";
}

void fn2()
{
	int i = 0;
	while(i != 100000000){
		i++;
	}
	std::cout << "Hi 2\n";
}

void fn3()
{
	int i = 0;
	while(i != 100000000){
		i++;
	}
	std::cout << "Hi 3\n";
}

int main()
{
	auto start = std::chrono::system_clock::now();

	std::thread t1(fn1);
	std::thread t2(fn2);
	std::thread t3(fn3);

	t1.join();
	t2.join();
	t3.join();

	auto end = std::chrono::system_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "The execution time is " << diff.count() << " microsec" << std::endl;

	return 0;
}
